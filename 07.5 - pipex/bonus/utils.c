/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:42:11 by thomas            #+#    #+#             */
/*   Updated: 2025/02/28 12:38:14 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(EXIT_FAILURE);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	open_file(char *file, int mode)
{
	int	fd;

	fd = 0;
	if (mode == 0)
	{
		if (access(file, F_OK | X_OK) != 0)
			return (error(PERM));
		fd = open(file, O_RDONLY);
	}
	else if (mode == 1)
	{
		if (access(file, F_OK) != 0)
			fd = open(file, O_CREAT | O_WRONLY, 0644);
		else if (access(file, X_OK) != 0)
			return (error(PERM));
		else
			fd = open(file, O_WRONLY);
	}
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
