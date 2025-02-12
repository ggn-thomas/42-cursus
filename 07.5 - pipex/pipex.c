/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:38:59 by thomas            #+#    #+#             */
/*   Updated: 2025/02/12 14:45:34 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"					

static void	ft_execute(char **envp, char *command)
{
	char	*path;
	char	**args;

	args = ft_split(command, ' ');
	if (!args)
		return ;
	path = find_path(envp, args[0]);
	if (!path)
	{
		ft_free_tab(args);
		printf("Command not found !\n");
		return ;
	}
	if (execve(path, args, NULL) == -1)
	{
		ft_free_tab(args);
		printf("Error executing command !\n !");
		exit(0);
	}
	free(path);
	ft_free_tab(args);
}

static void	parent_process(int *p_fd, char **av, char **envp)
{
	int	fd;

	close(p_fd[1]);
	fd = open_file(av[4], 1);
	if (fd == -1)
	{
		printf("Error !\n");
		return ;
	}
	dup2(fd, 1);
	close(fd);
	dup2(p_fd[0], 0);
	close(p_fd[0]);
	ft_execute(envp, av[3]);
}

static void	child_process(int *p_fd, char **av, char **envp)
{
	int		fd;
	
	close(p_fd[0]);
	fd = open_file(av[1], 0);
	if (fd == -1)
	{
		printf("Error !\n");
		return ;
	}
	dup2(fd, 0);
	close(fd);
	dup2(p_fd[1], 1);
	close(p_fd[1]);
	ft_execute(envp, av[2]);
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
		child_process(fd, av, envp);
	else if (pid > 0)
		parent_process(fd, av, envp);
	else
		return (0);
	return (1);
}
