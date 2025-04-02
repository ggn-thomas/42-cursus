/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokeniser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:16:52 by thgaugai          #+#    #+#             */
/*   Updated: 2025/04/01 14:04:29 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>


static int	process_redirections(t_line **current_token, t_line **list_token,
		t_command **current_cmd, t_command **lst_command)
{
	if ((*current_token)->mode == R_INPUT)
	{
		init_Rinput(current_token, lst_command, list_token, *current_cmd);
		*current_token = (*current_token)->next;
	}
	else if ((*current_token)->mode == R_OUTPUT
		|| (*current_token)->mode == DOUBLE_R)
	{
		init_Rouput(current_token, lst_command, list_token, *current_cmd);
		*current_token = (*current_token)->next;
	}
	else if ((*current_token)->mode == HERE_DOC)
		ft_here_doc(current_token, list_token, *current_cmd, lst_command);
	return (1);
}

void	process_token(t_line **current_token, t_line **list_token,
		t_command **current_cmd, t_command **lst_command)
{
	if (!*current_token)
		return ;
	if ((*current_token)->mode == PIPE)
	{
		(*current_cmd)->mode = (*current_token)->mode;
		process_pipe(current_token, list_token, current_cmd, lst_command);
	}
	else if (is_redirection((*current_token)->mode))
	{
		(*current_cmd)->mode = (*current_token)->mode;
		process_redirections(current_token, list_token, current_cmd, lst_command);
	}
	else
	{
		(*current_cmd)->mode = (*current_token)->mode;
		add_argument((*current_token)->data, *current_cmd, list_token, lst_command);
		*current_token = (*current_token)->next;
	}
}

t_command	**create_token(t_line **list_token)
{
	t_command	**lst_command;
	t_command	*current_cmd;
	t_line		*current_token;

	lst_command = malloc(sizeof(t_command));
	if (!lst_command)
		error(MALLOC, NULL, list_token, NULL);
	*lst_command = NULL;
	current_cmd = init_command();
	if (!current_cmd)
		error(MALLOC, NULL, list_token, NULL);
	add_command(current_cmd, lst_command);
	current_token = *list_token;
	while (current_token)
		process_token(&current_token, list_token, &current_cmd, lst_command);
	ft_free_list(list_token);
	return (lst_command);
}
