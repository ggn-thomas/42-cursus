/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:14:15 by thomas            #+#    #+#             */
/*   Updated: 2024/12/18 09:33:10 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include "../includes/so_long.h"

int	ft_count_element_stack(t_stack_line **map, char c)
{
	t_stack_line	*index;
	int				i;
	int				count;

	count = 0;
	i = 0;
	index = *map;
	while (index)
	{
		i = 0;
		while (index->str[i])
		{
			if (index->str[i] == c)
				count++;
			i++;
		}
		index = index->next;
	}
	return (count);
}

int	ft_count_element_tab(char **map, char c)
{
	int	x;
	int	y;
	int	counter;

	counter = 0;
	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == c)
				counter++;
			x++;
		}
		y++;
	}
	return (counter);
}

t_stack_line	*ft_lst_last(t_stack_line **map)
{
	t_stack_line	*index;

	if (!*map)
		return (NULL);
	index = *map;
	while (index->next)
		index = index->next;
	return (index);
}

t_point	find_start_position(char **map, char c)
{
	int		y;
	int		x;
	t_point	start;

	start.x = 0;
	start.y = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == c)
			{
				start.x = x;
				start.y = y;
				return (start);
			}
			x++;
		}
		y++;
	}
	return (start);
}
