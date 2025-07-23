/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arguments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:57:14 by thgaugai          #+#    #+#             */
/*   Updated: 2025/04/02 17:17:16 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	check_valid_pipe(t_line *index, t_line **lst_token)
{
	if (index->mode == PIPE)
	{
		if (index == *lst_token)
		{
			printf("%s '%s'\n", ERROR, index->data);
			return (0);
		}
		if (!index->next || index->next->mode == PIPE)
		{
			printf("%s '%s'\n", ERROR, index->data);
			return (0);
		}
	}
	return (1);
}

static int	check_valid_syntax(t_line **lst_token)
{
	t_line	*index;

	index = *lst_token;
	while (index)
	{
		if (index->mode == PIPE || index->mode == R_INPUT
			|| index->mode == R_OUTPUT || index->mode == HERE_DOC
			|| index->mode == DOUBLE_R)
		{
			if (!index->next)
			{
				printf("%s '%s'\n", ERROR, index->data);
				return (0);
			}
			else if (index->next->mode == PIPE || index->next->mode == R_INPUT
				|| index->next->mode == R_OUTPUT || index->next->mode == HERE_DOC
				|| index->next->mode == DOUBLE_R)
			{
				printf("%s '%s'\n", ERROR, index->data);
				return (0);
			}
		}
		if (!(check_valid_pipe(index, lst_token)))
			return (0);
		index = index->next;
	}
	return (1);
}

static int	create_list(char **tab_line, t_line **list_token)
{
	int	i;

	i = 0;
	while (tab_line[i])
	{
		if (have_operator_glued(tab_line[i]))
			check_operator_glued(tab_line[i], list_token, tab_line);
		else
		{
			if (!(had_token_in_list(tab_line[i], list_token)))
				error(MALLOC, tab_line, list_token, NULL);
		}
		i++;
	}
	if (!check_valid_syntax(list_token))
	{
		ft_free_list(list_token);
		ft_free_tab(tab_line);
		return (0);
	}
	ft_free_tab(tab_line);
	return (1);
}

static void	check_operator(t_line **list_token)
{
	if (ft_strcmp((*list_token)->data, "|") == 0)
		(*list_token)->mode = PIPE;
	else if (ft_strcmp((*list_token)->data, "<") == 0)
		(*list_token)->mode = R_INPUT;
	else if (ft_strcmp((*list_token)->data, ">") == 0)
		(*list_token)->mode = R_OUTPUT;
	else if (ft_strcmp((*list_token)->data, "<<") == 0)
		(*list_token)->mode = HERE_DOC;
	else if (ft_strcmp((*list_token)->data, ">>") == 0)
		(*list_token)->mode = DOUBLE_R;
}

void	check_type(t_line *list_token)
{
	if (ft_strcmp(list_token->data, "cd") == 0)
		list_token->mode = CD;
	else if (ft_strcmp(list_token->data, "echo") == 0)
		list_token->mode = ECHO;
	else if (ft_strcmp(list_token->data, "export") == 0)
		list_token->mode = EEXPORT;
	else if (ft_strcmp(list_token->data, "unset") == 0)
		list_token->mode = UNSET;
	else if (ft_strcmp(list_token->data, "env") == 0)
		list_token->mode = ENV;
	else if (ft_strcmp(list_token->data, "pwd") == 0)
		list_token->mode = PWD;
	else if (ft_strcmp(list_token->data, "exit") == 0)
		list_token->mode = EXIT;
	else
		list_token->mode = WORD;
	check_operator(&list_token);
}

t_command	**sort_arguments(char *line, t_env_var **env_cpy)
{
	t_line		**list_token;
	t_command	**list_command;
	char		**tab_line;

	tab_line = ft_split_operator(line);
	if (!tab_line)
		error(MALLOC, NULL, NULL, NULL);
	list_token = malloc(sizeof(t_line *));
	if (!list_token)
		error(MALLOC, tab_line, NULL, NULL);
	*list_token = NULL;
	if (!create_list(tab_line, list_token))
		return (NULL);
	list_command = create_token(list_token);
	if (*list_command && !((*list_command)->here_doc))
		select_exec(list_command, env_cpy);
	return (list_command);
}
