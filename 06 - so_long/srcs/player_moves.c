/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:45:53 by thgaugai          #+#    #+#             */
/*   Updated: 2024/12/18 12:04:29 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	draw_current_position_left(t_data *data, int tmp_x, int tmp_y)
{
	display_nb_key_press(data);
	if (data->map[data->player_position.y][data->player_position.x] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->exit,
			data->player_position.x * IMG_WIDTH, data->player_position.y
			* IMG_WIDTH);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->empty,
			data->player_position.x * IMG_WIDTH, data->player_position.y
			* IMG_WIDTH);
	mlx_put_image_to_window(data->mlx, data->win, data->player_left, tmp_x
		* IMG_WIDTH, tmp_y * IMG_WIDTH);
	data->player_position.x = tmp_x;
	data->player_position.y = tmp_y;
}

void	player_moves_left(int x, int y, t_data *data)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = 0;
	tmp_y = 0;
	tmp_x = data->player_position.x + x;
	tmp_y = data->player_position.y + y;
	if (data->map[tmp_y][tmp_x] == '1')
		return ;
	if (data->map[tmp_y][tmp_x] == 'E' && data->count == data->nb_exit)
	{
		display_win();
		ft_exit(data);
	}
	if (data->map[tmp_y][tmp_x] == 'C')
	{
		data->count++;
		data->map[tmp_y][tmp_x] = '0';
	}
	if (data->map[tmp_y][tmp_x] == 'X')
	{
		display_lose();
		ft_exit(data);
	}
	draw_current_position_left(data, tmp_x, tmp_y);
}

static void	draw_current_position_right(t_data *data, int tmp_x, int tmp_y)
{
	display_nb_key_press(data);
	if (data->map[data->player_position.y][data->player_position.x] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->exit,
			data->player_position.x * IMG_WIDTH, data->player_position.y
			* IMG_WIDTH);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->empty,
			data->player_position.x * IMG_WIDTH, data->player_position.y
			* IMG_WIDTH);
	mlx_put_image_to_window(data->mlx, data->win, data->player, tmp_x
		* IMG_WIDTH, tmp_y * IMG_WIDTH);
	data->player_position.x = tmp_x;
	data->player_position.y = tmp_y;
}

void	player_moves_right(int x, int y, t_data *data)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = 0;
	tmp_y = 0;
	tmp_x = data->player_position.x + x;
	tmp_y = data->player_position.y + y;
	if (data->map[tmp_y][tmp_x] == '1')
		return ;
	if (data->map[tmp_y][tmp_x] == 'E' && data->count == data->nb_exit)
	{
		display_win();
		ft_exit(data);
	}
	if (data->map[tmp_y][tmp_x] == 'C')
	{
		data->count++;
		data->map[tmp_y][tmp_x] = '0';
	}
	if (data->map[tmp_y][tmp_x] == 'X')
	{
		display_lose();
		ft_exit(data);
	}
	draw_current_position_right(data, tmp_x, tmp_y);
}
