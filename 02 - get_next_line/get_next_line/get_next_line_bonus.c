/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:13:47 by thomas            #+#    #+#             */
/*   Updated: 2024/11/08 14:20:38 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_join_all(int fd, char *buffer, char *stock)
{
	ssize_t		read_byte ;
	char		*temp;

	read_byte = 1;
	while (read_byte > 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(stock);
			return (NULL);
		}
		else if (read_byte == 0)
			break ;
		buffer[read_byte] = '\0';
		if (!stock)
			stock = ft_strdup("");
		temp = stock;
		stock = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stock);
}

static char	*ft_cut_buffer(char *line)
{
	ssize_t		i;
	char		*stock;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[1] == '\0')
		return (NULL);
	stock = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!*stock)
	{
		free(stock);
		return (NULL);
	}
	line[i + 1] = '\0';
	return (stock);
}

char	*get_next_line(int fd)
{
	static char	*stock[1024];
	char		*buffer;
	char		*line;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		free(stock[fd]);
		buffer = NULL;
		stock[fd] = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = ft_join_all(fd, buffer, stock[fd]);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	stock[fd] = ft_cut_buffer(line);
	return (line);
}
