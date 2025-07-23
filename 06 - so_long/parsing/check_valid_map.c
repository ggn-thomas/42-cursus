/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:00:04 by thomas            #+#    #+#             */
/*   Updated: 2024/12/18 12:15:30 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../gnl/get_next_line.h"
#include "../includes/so_long.h"

static int	check_rectangle(t_stack_line **map)
{
	t_stack_line	*index;
	int				len;
	int				len_verif;
	int				len_lst;
	int				i;

	len_lst = ft_lstlen(map) - 2;
	if (len_lst < 3 && ft_strlen(((*map)->str)) < 4)
		return (0);
	index = *map;
	len = ft_strlen(index->str);
	i = 0;
	while (i != len_lst)
	{
		len_verif = ft_strlen(index->next->str);
		if (len != len_verif)
			return (0);
		index = index->next;
		i++;
	}
	len_verif = ft_strlen(index->next->str);
	if (len_verif != len - 1)
		return (0);
	return (1);
}

static int	check_outline(t_stack_line **map)
{
	int				x;
	t_stack_line	*y;

	x = 0;
	y = *map;
	while (y->str[x] != '\n')
	{
		if (y->str[x] != '1')
			return (0);
		x++;
	}
	while (y->next)
	{
		if (y->str[0] != '1' || y->str[x - 1] != '1')
			return (0);
		y = y->next;
	}
	x = 0;
	while (y->str[x] != '\0')
	{
		if (y->str[x] != '1')
			return (0);
		x++;
	}
	return (1);
}

static int	check_content_map(t_stack_line **map)
{
	if (ft_count_element_stack(map, 'C') < 1)
	{
		write(1, "Error\n", 6);
		write(1, "Incorrect number of objects to collect !\n", 41);
		return (0);
	}
	if (ft_count_element_stack(map, 'E') != 1)
	{
		write(1, "Error\n", 6);
		write(1, "Incorrect number of outputs !\n", 30);
		return (0);
	}
	if (ft_count_element_stack(map, 'P') != 1)
	{
		write(1, "Error\n", 6);
		write(1, "Incorrect number of starting points !\n", 38);
		return (0);
	}
	if (ft_count_element_stack(map, 'X') < 1)
	{
		write(1, "Error\n", 6);
		write(1, "Incorrect number of enemy !\n", 29);
		return (0);
	}
	return (1);
}

static int	valid_syntax(t_stack_line **map)
{
	t_stack_line	*index;
	int				i;

	i = 0;
	index = *map;
	while (index)
	{
		i = 0;
		while (index->str[i])
		{
			if (index->str[i] != '1' && index->str[i] != '0'
				&& index->str[i] != 'E' && index->str[i] != 'C'
				&& index->str[i] != 'P' && index->str[i] != '\n'
				&& index->str[i] != 'X')
			{
				write(1, "Invalid caracter in your map !\n", 31);
				return (0);
			}
			i++;
		}
		index = index->next;
	}
	return (1);
}

int	ft_parsing(t_stack_line **map)
{
	if (!(check_rectangle(map)) || !(check_outline(map)))
	{
		write(1, "Error\nThe rectangle is incorrect !\n", 34);
		ft_free_stack(map);
		return (0);
	}
	else if (!(check_content_map(map)) || !(valid_syntax(map))
		|| !(check_len_map(map)))
	{
		ft_free_stack(map);
		return (0);
	}
	return (1);
}
