/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:15:19 by thgaugai          #+#    #+#             */
/*   Updated: 2025/02/27 15:29:56 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	**init_fd(int count_pipe)
{
	int	**tab_fd;
	int	i;

	i = 0;
	tab_fd = malloc(sizeof(int *) * count_pipe);
	if (!tab_fd)
		return (0);
	while (i < count_pipe)
	{
		tab_fd[i] = malloc(sizeof(int) * 2);
		if (!tab_fd)
		{
			while (i)
			{
				close(tab_fd[i][1]);
				close(tab_fd[i][0]);
				free(tab_fd[i]);
				i--;
			}
			free(tab_fd);
			return (0);
		}
		if (pipe(tab_fd[i]) == -1)
		{
			while (i)
			{
				close(tab_fd[i][1]);
				close(tab_fd[i][0]);
				free(tab_fd[i]);
				i--;
			}
			free(tab_fd);
			return (0);
		}
		i++;
	}
	return (tab_fd);
}

int	*init_tab_pid(int count_command)
{
	int	i;
	int	*tab_pid;

	tab_pid = malloc(sizeof(int) * count_command);
	if (!tab_pid)
		return (0);
	i = -1;
	while(++i < count_command)
	{
		tab_pid[i] = fork();
		if (tab_pid[i] == -1)
		{
			while (i)
			{
				free(tab_pid);
				return (0);
			}
		}
	}
	return (tab_pid);
}