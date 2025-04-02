/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:52:21 by thomas            #+#    #+#             */
/*   Updated: 2025/03/31 15:45:04 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	ft_print(t_line **list)
{
	t_line	*tmp;

	if (!*list)
		return ;
	tmp = *list;
	while (tmp->next)
	{
		printf("%s\n", tmp->data);
		tmp = tmp->next;
	}
}

static void	ft_while_heredoc(t_command *current_cmd, t_line **list,
		t_line **list_token, t_command **list_cmd)
{
	char	*rl;
	t_line	*new;

	while (1)
	{
		rl = readline("heredoc> ");
		if (!rl)
			break ;
		add_history(rl);
		new = ft_new_node(rl);
		if (!new)
			error_h(MALLOC, list, list_token, list_cmd);
		ft_lst_add_back(list, new);
		if (ft_strcmp(new->data, current_cmd->infile) == 0)
			break ;
		free(rl);
	}
}

void	ft_here_doc(t_line **current_token, t_line **list_token,
		t_command *current_cmd, t_command **lst_command)
{
	t_line	**list;

	current_cmd->here_doc = 1;
	list = malloc(sizeof(t_line *));
	if (!list)
		error(MALLOC, NULL, list_token, lst_command);
	*list = NULL;
	if (!(*current_token)->next)
	{
		error(ERR_RED, NULL, list_token, lst_command);
	}
	*current_token = (*current_token)->next;
	if (*current_token && (*current_token)->mode == WORD)
	{
		current_cmd->infile = ft_strdup((*current_token)->data);
		if (!current_cmd->infile)
			error(MALLOC, NULL, list_token, lst_command);
	}
	ft_while_heredoc(current_cmd, list, list_token, lst_command);
	ft_print(list);
	free(current_cmd->infile);
	current_cmd->infile = NULL;
}
