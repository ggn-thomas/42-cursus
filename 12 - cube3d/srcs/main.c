/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:56:22 by thgaugai          #+#    #+#             */
/*   Updated: 2025/06/12 16:10:10 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	main(int ac, char **av)
{
	(void)ac;
	char *line;
	t_map	*tmp;
	t_map	*map;
	t_map	*beg;
	int	fd;

	map = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error("Error: file descriptor is invalid!");
	line = get_next_line(fd);
	while (line != NULL)
	{
		tmp = ft_new_node(line);
		ft_lstadd_back(&map, tmp);
		line = NULL;
		line = get_next_line(fd);
	}
	close(fd);
	window_init(&map);

	/*beg = map;
	while (map)
	{
		printf("%s\n", (map)->line);
		map = (map)->next;
	}
	map = beg;
	while(map)
	{
		beg = map;
		map = (map)->next;
		free(beg->line);
		free(beg);
	}*/
	return 0;
}
