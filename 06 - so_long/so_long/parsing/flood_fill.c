/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:53:52 by thgaugai          #+#    #+#             */
/*   Updated: 2024/12/18 10:36:52 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_tablen(char **tab)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	i = 0;
	j = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			j++;
			len++;
		}
		i++;
	}
	return (len);
}

static int	finish_check(char **map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != 'x' && map[y][x] != '1' && map[y][x] != 'X')
			{
				write(1, "Error\n", 6);
				write(1, "No correct path found !\n", 24);
				return (0);
			}
			else
				x++;
		}
		y++;
	}
	return (1);
}

static void	ft_stock_neighbour(char **cpy_map, t_point index, t_point *stack,
		int *i)
{
	t_point	tmp;

	cpy_map[index.y][index.x] = 'x';
	tmp.x = index.x + 1;
	tmp.y = index.y;
	stack[(*i)++] = tmp;
	tmp.x = index.x - 1;
	stack[(*i)++] = tmp;
	tmp.x = index.x;
	tmp.y = index.y + 1;
	stack[(*i)++] = tmp;
	tmp.y = index.y - 1;
	stack[(*i)++] = tmp;
}

int	flood_fill(char **cpy_map)
{
	int		i;
	t_point	index;
	t_point	*stack;

	stack = malloc(sizeof(t_point) * (ft_tablen(cpy_map) * 4));
	index = find_start_position(cpy_map, 'P');
	i = 0;
	stack[i++] = index;
	while (i > 0)
	{
		index = stack[--i];
		if (cpy_map[index.y][index.x] != '1' && cpy_map[index.y][index.x] != 'x'
			&& cpy_map[index.y][index.x] != 'X')
			ft_stock_neighbour(cpy_map, index, stack, &i);
	}
	if (!(finish_check(cpy_map)))
	{
		free(stack);
		ft_free_tab(cpy_map);
		return (0);
	}
	free(stack);
	return (1);
}
