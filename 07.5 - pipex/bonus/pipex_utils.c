/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:22:46 by thgaugai          #+#    #+#             */
/*   Updated: 2025/02/27 15:29:54 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_execute(char **envp, char *command)
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

int	open_file(char *file, int mode)
{
	int	fd;

	fd = 0;
	if (mode == 0)
		fd = open(file, O_RDONLY);
	else if (mode == 1)
		fd = open(file, O_WRONLY);
	return (fd);
}

char	*find_path(char **envp, char *command)
{
	int i;
	char **all_path;
	char *path;
	char *tmp;

	i = 0;
	while (envp[i] && !ft_strnstr(envp[i], "PATH", 4))
		i++;
	all_path = ft_split(envp[i] + 5, ':');
	tmp = ft_strjoin("/", command);
	i = -1;
	while (all_path[++i])
	{
		path = ft_strjoin(all_path[i], tmp);
		if (access(path, F_OK | X_OK) == 0)
		{
			free(tmp);
			ft_free_tab(all_path);
			return (path);
		}
		free(path);
	}
	free(tmp);
	ft_free_tab(all_path);
	return (NULL);
}