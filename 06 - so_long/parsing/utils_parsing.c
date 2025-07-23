/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:28:42 by thgaugai          #+#    #+#             */
/*   Updated: 2024/12/18 12:14:58 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../gnl/get_next_line.h"
#include "../includes/so_long.h"

int	check_len_map(t_stack_line **map)
{
	int				y;
	int				x;
	t_stack_line	*index;

	y = 0;
	index = *map;
	x = ft_strlen(index->str) * IMG_WIDTH;
	while (index)
	{
		index = index->next;
		y++;
	}
	y *= IMG_WIDTH;
	if (y > 1000 || x > 1920)
	{
		ft_printf("Error\nThe map is too large to be displayed\n");
		return (0);
	}
	return (1);
}
