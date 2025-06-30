/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:56:22 by thgaugai          #+#    #+#             */
/*   Updated: 2025/06/30 12:42:12 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_print(char **map)
{
	int	i = 0;

	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

int	counter_line(char *file)
{
	int	fd;
	char *line;
	int	counter;
	
	counter = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("Error: file descriptor is invalid!");
	line = get_next_line(fd);
	while (line != NULL)
	{
		counter++;
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	close(fd);
	return (counter);
}

char	**map_init(char *file)
{
	char **map;
	char *line;
	int	i;
	int	fd;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("Error: file descriptor is invalid!");
	map = malloc(sizeof(char*) * (counter_line(file) + 1));
	if (!map)
		error("Error: Memory allocation failed!");
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i] = ft_strdup(line);
		free(line);
		line = NULL;
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int	main(int ac, char **av)
{
	(void)ac;
	char	**map;
	
	map = map_init(av[1]);
	init(map);
	return (0);
}
