/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:38:59 by thomas            #+#    #+#             */
/*   Updated: 2025/02/11 12:08:51 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **envp)
{
	int		i;
	char	**path;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	path = ft_split(envp[i] + 5, ":");
}
void	child_process(int *fd)
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	execve();
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
		child_process(fd[2]);
	else if (pid > 0)
		parent_process(fd);
	else
		return (0);
	return (1);
}
