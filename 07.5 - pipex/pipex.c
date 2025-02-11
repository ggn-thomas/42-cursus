/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:38:59 by thomas            #+#    #+#             */
/*   Updated: 2025/02/11 15:42:44 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int *p_fd, char **av, char **envp)
{
	int		fd;
	
	fd = open_file(av[0]);
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	execute();
}

int	main(int ac, char **av, char **envp)
{
	int	fd[2];
	int	pid;

	pid = 0;
	if (ac != 5)
		return (1);
	if (pipe(fd) == -1)
		return (1);
	pid = fork();
	if (pid == 0)
		child_process(fd);
	else if (pid > 0)
		parent_process(fd);
	else
		return (0);
	return (1);
}
