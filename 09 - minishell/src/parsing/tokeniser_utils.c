/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokeniser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:01:08 by thgaugai          #+#    #+#             */
/*   Updated: 2025/04/02 14:39:59 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_command	*init_command(void)
{
	t_command	*command;

	command = malloc(sizeof(t_command));
	if (!command)
		return (NULL);
	command->args = malloc(sizeof(t_line *));
	if (!command->args)
		return (NULL);
	(*command->args) = NULL;
	command->next = NULL;
	command->outfile = NULL;
	command->infile = NULL;
	command->in_fd = 0;
	command->out_fd = 1;
	command->mode = 0;
	command->command = NULL;
	command->here_doc = 0;
	return (command);
}

void	add_command(t_command *new_node, t_command **lst_command)
{
	t_command	*last;

	if (!*lst_command)
	{
		*lst_command = new_node;
		return ;
	}
	last = *lst_command;
	while (last->next)
		last = last->next;
	last->next = new_node;
}

void	add_argument(char *data, t_command *current_cmd, t_line **list_token,
		t_command **lst_cmd)
{
	t_line	*tmp;

	if (!current_cmd)
		return ;
	if (current_cmd->command == NULL)
	{
		current_cmd->command = ft_strdup(data);
		if (!(current_cmd->command))
			error(MALLOC, NULL, list_token, lst_cmd);
		return ;
	}
	tmp = ft_new_node(data);
	if (!tmp)
		return ;
	if (!*current_cmd->args)
		*current_cmd->args = tmp;
	else
		ft_lst_add_back(current_cmd->args, tmp);
}

int	is_redirection(int mode)
{
	return (mode == PIPE || mode == R_OUTPUT || mode == R_INPUT
		|| mode == HERE_DOC || mode == DOUBLE_R);
}

void	process_pipe(t_line **current_token, t_line **list_token,
		t_command **current_cmd, t_command **lst_command)
{
	if (!(*current_token)->next)
		error(ERR_PIPE, NULL, list_token, lst_command);
	*current_cmd = init_command();
	if (!*current_cmd)
		error(MALLOC, NULL, list_token, lst_command);
	add_command(*current_cmd, lst_command);
	*current_token = (*current_token)->next;
}
