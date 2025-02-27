/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:42:11 by thomas            #+#    #+#             */
/*   Updated: 2025/02/12 14:49:38 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

int    open_file(char *file, int mode)
{
    int fd;

	fd = 0;
	if (mode == 0)
    	fd = open(file, O_RDONLY);
	else if (mode == 1)
		fd = open(file, O_WRONLY);
    return(fd);
}

char	*find_path(char **envp, char *command)
{
	int		i;
	char	**all_path;
	char	*path;
	char	*tmp;
	
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