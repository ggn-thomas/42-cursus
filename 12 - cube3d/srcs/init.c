/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:57:11 by thgaugai          #+#    #+#             */
/*   Updated: 2025/06/15 10:47:22 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	load_sprites(t_data *data)
{
	int	w;

	w = IMG_WIDTH;
	data->EA = mlx_xpm_file_to_image(data->mlx, "textures/wood.xpm", &w, &w);
	data->WE = mlx_xpm_file_to_image(data->mlx, "textures/wood.xpm", &w, &w);
	data->SO = mlx_xpm_file_to_image(data->mlx, "textures/wall_3.xpm", &w, &w);
	data->NO = mlx_xpm_file_to_image(data->mlx, "textures/wall_3.xpm", &w, &w);
	data->F[0] = 255;
	data->F[1] = 255;
	data->F[2] = 0;
	data->C[0] = 255;
	data->C[1] = 255;
	data->C[2] = 0;

}


int	window_init(t_map **map)
{
	t_data	data;

	data.mlx = mlx_init();
	if (!data.mlx)
		error("Error: Minilibx: Initializing failed!");
	data.map = map;
	data.size_x = 0;
	data.size_y = 0;
	data.win = mlx_new_window(data.mlx, data.size_x, data.size_y, "Cube3d");
	if (!data.win)
		error("Error: Minilibx: Window creation failed!");
	mlx_hook(data.win, 2, 1L << 0, ft_keypress, &data);
	load_sprites(&data);
	mlx_loop(data.mlx);
	draw_background(&data);
}

int	init(t_map **map)
{
	t_data data;
	t_ray	ray;

	data.player->x = 0;
	data.player->y = 0;
	data.player->dir_x = -1;
	data.player->dir_y = 0;
	data.player->plane_x = 0;
	data.player->plane_y = 0.66;
	window_init(map);
	init_ray(&ray, &data);
	game_loop(&data.player, &ray);
}
