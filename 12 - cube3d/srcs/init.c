/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:57:11 by thgaugai          #+#    #+#             */
/*   Updated: 2025/06/30 13:58:28 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"


t_ray	*ray_init(void)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		exit(EXIT_FAILURE);
	ray->delta_dist_x = 0;
	ray->delta_dist_y = 0;
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->perp_wall_dist = 0;
	ray->side_dist_x = 0;
	ray->side_dist_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->screen_heigth = 0;
	return (ray);
}

t_data	data_init(char **map)
{
	t_data	data;
	
	data.player  = malloc(sizeof(t_player));
	if (!data.player)
		exit(EXIT_FAILURE);
	data.size_x = SIZE_X;
	data.size_y = SIZE_Y;
	data.player->x = 4;
	data.player->y = 4;
	data.player->dir_x = -1;
	data.player->dir_y = 0;
	data.player->plane_x = 0;
	data.player->plane_y = 0.66;
	data.player->move_speed = 0.1;
	data.img_data = 0;
	data.bits_per_pixel = 0;
	data.line_length = 0;
	data.img = NULL;
	data.mlx = mlx_init();
	if (!data.mlx)
		error("Error: Minilibx: Initializing failed!");
	data.map = map;
	data.win = mlx_new_window(data.mlx, data.size_x, data.size_y, "Cube3d");
	if (!data.win)
		error("Error: Minilibx: Window creation failed!");
	data.img = mlx_new_image(data.mlx, data.size_x, data.size_y);
	if (!data.img)
		error("Error: Minilibx: Image creation failed!");
	data.img_data = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	data.ray = ray_init();
	return (data);
}

void	init(char **map)
{
	t_data	data;

	data = data_init(map);
	//ft_print(data.map);
	load_sprites(&data);
	mlx_hook(data.win, 2, 1L << 0, ft_keypress, &data);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
}
