/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:38:59 by thomas            #+#    #+#             */
/*   Updated: 2025/02/28 12:51:29 by thgaugai         ###   ########.fr       */
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

void	ft_pipe(char **envp, char *cmd)
{
	pid_t	pid;
	int	p_fd[2];

	if (pipe(p_fd) == -1)
		return ;
	pid = fork();
	if (pid == -1)
		return ;
	if (!pid)
	{
		close(p_fd[0]);
		dup2(p_fd[1], 1);
		ft_execute(envp, cmd);
	}
	else
	{
		waitpid(pid, 0, 0);
		close(p_fd[1]);
		dup2(p_fd[0], 0);
	}
}

int	main(int ac, char **av, char **envp)
{
	int	i;
	int	fd_infile;
	int	fd_outfile;

	fd_infile = open_file(av[1], 0);
	fd_outfile = open_file(av[ac - 1], 1);
	dup2(fd_infile, 0);
	i = 1;
	while(++i < ac - 2)
		ft_pipe(envp, av[i]);
	dup2(fd_outfile, 1);
	ft_execute(envp, av[ac - 2]);
	close(fd_infile);
	close(fd_outfile);
	return (1);
}
