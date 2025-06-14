/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 10:46:57 by thgaugai          #+#    #+#             */
/*   Updated: 2025/06/15 11:37:03 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

static void	ray_direction(t_data *data, t_player *player, t_ray *ray, int x)
{
	double	camera_x;

	//calcul de la direction du rayon
	camera_x = 2 * x / (double)data->size_x - 1;
	ray->dir_x = player->dir_x + player->plane_x * camera_x;
	ray->dir_y = player->dir_y + player->plane_y * camera_x;
	//calculer la distance que le rayon doit parcourir pour passer d'une ligne
	// verticale à la suivante (x) ou d'une ligne horizontale à la suivante (y).
	ray->delta_dist_x = (ray->dir_x == 0) ? 1e30 : fabs(1 / ray->dir_x);
	ray->delta_dist_y = (ray->dir_y == 0) ? 1e30 : fabs(1 / ray->dir_y);
}

static void	ray_distance(t_ray	*ray, t_player *player, int *map_x, int *map_y)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->x - *map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (*map_x + 1.0 - player->x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->y - *map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (*map_y + 1.0 - player->y) * ray->delta_dist_y;
	}
}

static void	check_hit_wall(t_data *data, t_ray *ray, int *map_x, int *map_y)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			*map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			*map_y += ray->step_y;
			ray->side = 1;
		}
		if (data->map[*map_y]->line[*map_x] > 0)
			ray->hit = 1;
	}
}

static void	perpendicular_distance(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
}

void	wall_heigth(t_ray *ray, t_data *data)
{
	int	line_heigth;
	int	draw_start;
	int	draw_end;

	line_heigth = (int)(ray->screen_heigth / ray->perp_wall_dist);
	data->draw_start = -line_heigth / 2 + ray->screen_heigth /2;
	data->draw_end = line_heigth / 2 + ray->screen_heigth / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	if (data->draw_end >= ray->screen_heigth)
		data->draw_end = ray->screen_heigth - 1;
}

void	ray(t_ray *ray, t_player *player, t_data *data)
{
	int	x;
	int	map_x;
	int	map_y;
	int	side;

	map_x = player->x;
	map_y = player->y;
	side = 0;
	x = -1;
	while (++x < data->size_x)
	{
		ray_direction(data, player, ray, x);
		ray_distance(ray, player, &map_x, &map_y);
		check_hit_wall(data, ray, map_x, map_y);
		perpendicular_distance(ray);
	}
}
