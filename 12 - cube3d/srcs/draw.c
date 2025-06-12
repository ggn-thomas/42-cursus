/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:21:20 by thgaugai          #+#    #+#             */
/*   Updated: 2025/06/12 17:10:23 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

/*
void	draw_background(t_data *data)
{
	int x;
	int y;
	void *sprites;

	sprites = NULL;
	y = 0;
	x = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[x])
		{
			sprites = data->;
			mlx_put_image_to_window(data->mlx, data->win, sprites, x
				* IMG_WIDTH, y * IMG_WIDTH);
			x++;
		}
		y++;
	}
}*/
void	draw(void *sprite, t_data *data, int x, int y)
{
	if (data->map[y][x] != )
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;
	void	*sprite;

	x = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			sprite = NULL;
			draw(sprite, data, x, y);
			x++;
		}
		y++;
	}
}