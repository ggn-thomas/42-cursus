/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:05:12 by thgaugai          #+#    #+#             */
/*   Updated: 2024/07/31 16:39:39 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

size_t	get_file_size(char *filename)
{
	char		*buffer;
	size_t		size;
	int			fd;

	fd = open(filename, O_RDWR);
	size = 0;
	while (read(fd, &buffer, 1))
		size++;
	close(fd);
	return (size + sizeof(char));
}

void	run_prog(int fd, size_t size)
{
	char	*buffer;

	buffer = malloc(size);
	read(fd, buffer, size);
	search_number(buffer);
	free(buffer);
	close(fd);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*mapname;

	fd = -1;
	if (argc < 2 || argc > 2)
	{
		write (1, "Error with your input\n", 6);
		return (1);
	}
	mapname = argv[1];
	fd = open(mapname, O_RDWR);
	run_prog(fd, get_file_size(mapname));
}
