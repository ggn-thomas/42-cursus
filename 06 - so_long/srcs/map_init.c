/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:18:05 by thomas            #+#    #+#             */
/*   Updated: 2025/07/01 11:19:17 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../gnl/get_next_line.h"
#include "../includes/so_long.h"
#include "../libft/libft.h"

static t_stack_line	*ft_new_node(char *new_line)
{
	t_stack_line	*new;

	new = malloc(sizeof(t_stack_line));
	if (!new)
		return (NULL);
	new->str = ft_strdup(new_line);
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

static void	ft_add_back(t_stack_line **map, t_stack_line *new_node)
{
	t_stack_line	*last;

	last = ft_lst_last(map);
	if (!last)
		*map = new_node;
	else
	{
		last->next = new_node;
		new_node->prev = last;
	}
}

static char	**stack_to_tab(t_stack_line **lst_map)
{
	t_stack_line	*index;
	char			*str;
	char			*tmp;
	char			**map;

	str = ft_strdup("");
	index = *lst_map;
	while (index)
	{
		tmp = str;
		str = ft_strjoin(tmp, index->str);
		free(tmp);
		tmp = NULL;
		index = index->next;
	}
	map = ft_split(str, '\n');
	free(str);
	return (map);
}

static t_stack_line	*stack_init(void *param)
{
	int				fd;
	char			*line;
	t_stack_line	*tmp;
	t_stack_line	*map;

	map = NULL;
	fd = open(param, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\nFile descriptor is invalid !\n", 35);
		return (0);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		tmp = ft_new_node(line);
		ft_add_back(&map, tmp);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}

char	**map_init(char *param)
{
	t_stack_line	*map_lst;
	char			**map;
	char			**cpy_map;

	map_lst = stack_init(param);
	if (!map_lst)
	{
		ft_printf("Error\nThe file is empty !\n");
		exit(0);
	}
	if (!(ft_parsing(&map_lst)))
		exit(0);
	cpy_map = stack_to_tab(&map_lst);
	if (!(flood_fill(cpy_map)))
	{
		ft_free_stack(&map_lst);
		exit(0);
	}
	map = stack_to_tab(&map_lst);
	ft_free_stack(&map_lst);
	ft_free_tab(cpy_map);
	return (map);
}
