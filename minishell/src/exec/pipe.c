/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:24:57 by thgaugai          #+#    #+#             */
/*   Updated: 2025/04/02 14:07:43 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static pid_t	execute_last_cmd(t_command *cmd, t_command **lst, t_env_var **env_cpy, int *tab_pid)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (0);
	if (!pid)
	{
		check_exec(cmd, lst, env_cpy);
		ft_free_list_cmd(lst);
		ft_free_list_env(env_cpy);
		free(tab_pid);
		exit(0);
	}
	return (pid);
}

static void	children_process(int *p_fd)
{
	close(p_fd[0]);
	dup2(p_fd[1], 1);
	close(p_fd[1]);
}

static pid_t	ft_pipe(t_command *index, t_command **lst_cmd, t_env_var **env_cpy, int *tab_pid)
{
	pid_t	pid;
	int	p_fd[2];

	if (pipe(p_fd) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
	{
		close(p_fd[0]);
		close(p_fd[1]);
		return (-1);
	}
	if (!pid)
	{
		children_process(p_fd);
		check_exec(index, lst_cmd, env_cpy);
		ft_free_list_cmd(lst_cmd);
		ft_free_list_env(env_cpy);
		free(tab_pid);
		exit(0);
	}
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], 0);
		close(p_fd[0]);
	}
	return (pid);
}

static void	finish_process(int *tab_pid, int len_pid)
{
	int	i;

	i = 0;
	while (i < len_pid)
	{
		if (tab_pid[i] > 0)
			waitpid(tab_pid[i], NULL, 0);
		i++;
	}
	free(tab_pid);
}

static int *init_tab_pid(t_command **lst, t_env_var **env_cpy, int *len_pid)
{
	int	*tab_pid;
	int	len;
	t_command	*index;

	len = 0;
	index = *lst;
	while(index)
	{
		(*len_pid)++;
		len++;
		index = index->next;
	}
	tab_pid = malloc(sizeof(pid_t) * len);
	if (!tab_pid)
		error_l(MALLOC, lst, env_cpy);
	return (tab_pid);
}

int	ft_execute_pipe(t_command **lst, t_env_var **env_cpy)
{
	int	len_pid;
	int	*tab_pid;
	t_command	*index;
	int	i;

	len_pid = 0;
	i = 0;
	tab_pid = init_tab_pid(lst, env_cpy, &len_pid);
	index = *lst;
	while (index)
	{
		if (index->next)
			tab_pid[i++] = ft_pipe(index, lst, env_cpy, tab_pid);
		else
			tab_pid[i++] = execute_last_cmd(index, lst, env_cpy, tab_pid);
		index = index->next;
	}
	finish_process(tab_pid, len_pid);
	return (1);
}
