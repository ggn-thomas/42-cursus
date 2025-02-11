/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:42:11 by thomas            #+#    #+#             */
/*   Updated: 2025/02/11 15:47:15 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


char    open_file(int fd)
{
    int final_fd;

    final_fd = open(fd, O_RDONLY);
    return(final_fd);
}
char	*find_path(char **envp, char *command)
{
	int		i;
	char	**tab_path;
	char	*path;
	char	*tmp;
	
	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	tab_path = ft_split(envp[i] + 5, ":");
	tmp = ft_strjoin("/", command);
	i = -1;
	while (tab_path[++i])
	{
		path = ft_strjoin(tab_path[i], command);
		if (access(path, F_OK | X_OK) == 0)
		{
			free(tmp);
			free(tab_path);
			return (path);
		}
		free(path);
	}
	free(tmp);
	free(tab_path);
	free(path);
	return (NULL);
}