/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:18:11 by thgaugai          #+#    #+#             */
/*   Updated: 2025/03/31 17:19:03 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	open_file(char *file, int mode)
{
	int	fd;

	fd = 0;
	if (mode == 0)
	{
		if (access(file, F_OK | R_OK) != 0)
			return (-1);
		fd = open(file, O_RDONLY);
	}
	else if (mode == 1)
	{
		if (access(file, F_OK) != 0)
			fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		else
		{
			if (access(file, W_OK) != 0)
				return (-1);
			fd = open(file, O_WRONLY | O_TRUNC);
		}
	}
	return (fd);
}

static void	handle_append_redirection(t_command *index, t_command **lst_cmd,
		t_env_var **env)
{
	if (access(index->outfile, F_OK) != 0)
		index->out_fd = open(index->outfile, O_CREAT | O_WRONLY | O_APPEND,
				0644);
	else if (access(index->outfile, W_OK) != 0)
		error_l(PERM, lst_cmd, env);
	else
		index->out_fd = open(index->outfile, O_WRONLY | O_APPEND);
	if (index->out_fd == -1)
		error_l(PERM, lst_cmd, env);
	dup2(index->out_fd, 1);
	close(index->out_fd);
}

void	check_redirection(t_command *index, t_command **lst_cmd,
		t_env_var **env)
{
	if (!index->outfile && !index->infile)
		return ;
	else if (index->outfile)
	{
		if (index->mode == R_OUTPUT)
		{
			index->out_fd = open_file(index->outfile, 1);
			if (index->out_fd == -1)
				error_l(PERM, lst_cmd, env);
			dup2(index->out_fd, 1);
			close(index->out_fd);
		}
		else
			handle_append_redirection(index, lst_cmd, env);
	}
	else if (index->infile)
	{
		index->in_fd = open_file(index->infile, 0);
		if (index->in_fd == -1)
			error_l(FD, lst_cmd, env);
		dup2(index->in_fd, 0);
		close(index->in_fd);
	}
}

void	check_exec(t_command *index, t_command **lst_cmd, t_env_var **env_cpy)
{
	check_redirection(index, lst_cmd, env_cpy);
	if (ft_strcmp(index->command, "cd") == 0)
		ft_cd(index);
	else if (ft_strcmp(index->command, "echo") == 0)
		ft_echo(index);
	else if (ft_strcmp(index->command, "export") == 0)
		ft_export(index, env_cpy);
	// else if (ft_strcmp(index->command, "unset") == 0)
	// 	ft_unset(index);
	else if (ft_strcmp(index->command, "env") == 0)
		ft_env(env_cpy);
	else if (ft_strcmp(index->command, "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(index->command, "exit") == 0)
		ft_exit(lst_cmd);
	else if (index->mode == PIPE)
		ft_execve_pipe(index);
	else
		ft_execve(index);
}

void	select_exec(t_command **list, t_env_var **env_cpy)
{
	int	saved_stdout;
	int	saved_stdin;

	saved_stdout = dup(STDOUT_FILENO);
	saved_stdin = dup(STDIN_FILENO);
	if ((*list)->mode == PIPE)
		ft_execute_pipe(list, env_cpy);
	else
		check_exec(*list, list, env_cpy);
	dup2(saved_stdout, STDOUT_FILENO);
	dup2(saved_stdin, STDIN_FILENO);
	close(saved_stdout);
	close(saved_stdin);
}
