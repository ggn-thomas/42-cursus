/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:24:16 by thgaugai          #+#    #+#             */
/*   Updated: 2024/12/18 12:10:34 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnl/get_next_line.h"
#include "../includes/so_long.h"
#include "../libft/libft.h"

void	display_nb_key_press(t_data *data)
{
	int		x;
	int		y;
	char	*nb_key_press;

	data->count_key++;
	nb_key_press = ft_itoa(data->count_key);
	x = (count_column(data->map) - 1) * IMG_WIDTH + 11;
	y = 25;
	mlx_put_image_to_window(data->mlx, data->win, data->counter, x - 11, 0);
	mlx_string_put(data->mlx, data->win, x, y, 0xFFFFFF, nb_key_press);
	free(nb_key_press);
}

void	draw_counter(t_data *data)
{
	int	x;
	int	y;

	x = count_column(data->map) - 1;
	y = 0;
	mlx_put_image_to_window(data->mlx, data->win, data->counter, x * IMG_WIDTH,
		y * IMG_WIDTH);
}

void	draw_background(t_data *data)
{
	int		y;
	int		x;
	void	*sprite;

	sprite = NULL;
	y = 0;
	x = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			sprite = data->empty;
			mlx_put_image_to_window(data->mlx, data->win, sprite, x * IMG_WIDTH,
				y * IMG_WIDTH);
			x++;
		}
		y++;
	}
}

static void	draw(void *sprite, t_data *data, int x, int y)
{
	if (data->map[y][x] == '1')
		sprite = data->wall;
	if (data->map[y][x] == 'P')
		sprite = data->player;
	if (data->map[y][x] == 'E')
		sprite = data->exit;
	if (data->map[y][x] == 'C')
		sprite = data->collectible;
	if (data->map[y][x] == 'X')
		sprite = data->enemy;
	if (sprite)
		mlx_put_image_to_window(data->mlx, data->win, sprite, x * IMG_WIDTH, y
			* IMG_WIDTH);
	return ;
}

void	draw_map(t_data *data)
{
	int		x;
	int		y;
	void	*sprite;

	sprite = NULL;
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
