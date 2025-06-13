/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:57:11 by thgaugai          #+#    #+#             */
/*   Updated: 2025/06/13 16:38:55 by thgaugai         ###   ########.fr       */
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
int	game_loop(t_player *player, t_ray *ray, t_data *data)
{
	int	i;

	i = 0;
	while (1)
	{
		while (i++ < data->size_x)
		{
			ray->dir_x = player->dir_x * data->size_x
		}

	}
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
	//mlx_hook(data.win, 2, 1L << 0, ft_keypress, &data);
	load_sprites(&data);
	mlx_loop(data.mlx);
	draw_background(&data);
}

void	init_ray(t_ray *ray, t_player *player, t_data *data)
{
	double cameraX;
	int	x;
	int	map_x;
	int	map_y;
	int	side;

	side = 0;
	x = -1;
	while (++x < data->size_x)
	{
		//calcul de la direction du rayon
		cameraX = 2 * x / (double)data->size_x - 1;
		ray->dir_x = player->dir_x + player->plane_x * cameraX;
		ray->dir_y = player->dir_y + player->plane_y * cameraX;

		//calculer la distance que le rayon doit parcourir pour passer d'une ligne
		// verticale à la suivante (x) ou d'une ligne horizontale à la suivante (y).
		ray->delta_dist_x = (ray->dir_x == 0) ? 1e30 : fabs(1 / ray->dir_x);
		ray->delta_dist_y = (ray->dir_y == 0) ? 1e30 : fabs(1 / ray->dir_y);

		if (ray->dir_x < 0)
		{
			ray->step_x = -1;
			ray->side_dist_x = (player->x - map_x) * ray->delta_dist_x;
		}
		else
		{
			ray->step_x = 1;
			ray->side_dist_x = (map_x + 1.0 - player->x) * ray->delta_dist_x;
		}
		if (ray->dir_y < 0)
		{
			ray->step_y = -1;
			ray->side_dist_y = (player->y - map_y) * ray->delta_dist_y;
		}
		else
		{
			ray->step_y = 1;
			ray->side_dist_y = map(map_y + 1.0 - player->y) * ray->delta_dist_y;
		}

		while (ray->hit == 0)
		{
			if (ray->side_dist_x < ray->side_dist_y)
			{
				ray->side_dist_x += ray->delta_dist_x;
				map_x += ray->step_x;
				side = 0;
			}
			else
			{
				ray->side_dist_y = ray->delta_dist_y;
				map_y += ray->step_y;
				side = 1;
			}
			if (data->map[map_y]->line[map_x] > 0)
				ray->hit = 1;
		}
		if (ray->side == 0)
			ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
		else
			ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
	}

}
int	init(t_map **map)
{
	t_data data;
	t_ray	ray;
	t_player	player;

	player.x = 0;
	player.y = 0;
	player.dir_x = -1;
	player.dir_y = 0;
	player.plane_x = 0;
	player.plane_y = 0.66;
	window_init(map);
	init_ray(&ray, &player, &data);
	game_loop(&player, &ray);
}
