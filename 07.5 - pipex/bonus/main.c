/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:53:18 by thgaugai          #+#    #+#             */
/*   Updated: 2025/02/27 15:36:50 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_all_fd(int *tab_fd, int i)
{
	while (i--)
	{
		close(tab_fd[i][1]);
		close(tab_fd[i][0]);
	}
}

void	handle_first_process(int **tab_fd, char **envp, char **av, int cmd_index)
{
	int	fd;

	close(tab_fd[cmd_index][0]);
	fd = open_file(av[1], 0);
	if (fd == -1)
	{
		printf("Error !\n");
		return ;
	}
	dup2(fd, 0);
	close(fd);
	dup2(tab_fd[0][1], 1);
	close(tab_fd[cmd_index][1]);
	ft_execute(envp, av[2]);
}

void	handle_middle_process(int *tab_fd, char **envp, char **av, int cmd_index)
{
	dup2(tab_fd[cmd_index - 2], 0);
	dup2(tab_fd[cmd_index - 1], 1);
	close_all_fd(tab_fd, cmd_index);
	ft_execute(envp, av[cmd_index]);

}

void	handle_last_process(int **tab_fd, char **envp, char **av, int cmd_index)
{
	int	fd;

	close(tab_fd[cmd_index][1]);
	fd = open_file(av[cmd_index], 0);
	if (fd == -1)
	{
		printf("Error !\n");
		return ;
	}
	dup2(fd, 1);
	close(fd);
	dup2(tab_fd[cmd_index][0], 0);
	close(tab_fd[cmd_index][0]);
	ft_execute(envp, av[cmd_index]);

}


int	pipex(int ac, char **av, char **envp)
{
	int	**tab_fd;
	int	*tab_pid;
	int	count_pipe;
	int	count_command;
	int	i;
	int	status;

	count_command = ac - 3;
	count_pipe = count_command - 1;
	tab_fd = init_fd(count_pipe);
	if (!tab_fd)
		return (0);
	tab_pid = init_tab_pid(count_pipe);
	if (!tab_pid)
		return (0);
	i = -1;
	while (tab_pid[++i])
	{
		if (i == 0)
			handle_first_process(tab_fd, envp, av ,i);
		else if (i == count_command)
			handle_last_process(tab_fd, envp, av, i);
		else
			handle_middle_process(tab_fd, envp, av, i);
	}
	i = -1;
	while (tab_pid[++i])
	{
		waitpid(tab_pid[i], &status, 0);
	}
	return (1);
}
