/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:49:27 by thomas            #+#    #+#             */
/*   Updated: 2025/03/31 15:43:30 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	init_Rinput(t_line **current_token, t_command **lst_command,
		t_line **list_token, t_command *current_cmd)
{
	if (!(*current_token)->next)
		error(ERR_RED, NULL, list_token, lst_command);
	*current_token = (*current_token)->next;
	if (*current_token && (*current_token)->mode == WORD)
	{
		current_cmd->infile = ft_strdup((*current_token)->data);
		if (!current_cmd->infile)
			error(MALLOC, NULL, list_token, lst_command);
	}
}

void	init_Rouput(t_line **current_token, t_command **lst_command,
		t_line **list_token, t_command *current_cmd)
{
	if (!(*current_token)->next)
		error(ERR_RED, NULL, list_token, lst_command);
	*current_token = (*current_token)->next;
	if (*current_token && (*current_token)->mode == WORD)
	{
		current_cmd->outfile = ft_strdup((*current_token)->data);
		if (!current_cmd->outfile)
			error(MALLOC, NULL, list_token, lst_command);
	}
}
