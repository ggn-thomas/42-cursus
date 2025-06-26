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

void	draw_vertical_line(t_player *player, t_data *data, t_ray *ray, int x)
{
	void	*texture;
	int	y;
	int tex_x;
	int	tex_y;
	int	color;
	double	wall_x;

	y = 0;
	tex_x = 0;
	tex_y = 0;
	color = 0;
	wall_x = 0;
	texture = get_wall_texture(data, ray);
	if (ray->side == 0)
		wall_x = player->y + ray->perp_wall_dist * ray->dir_y;
	else
		wall_x = player->x + ray->perp_wall_dist * ray->dir_x;
	tex_x = (int)(wall_x * IMG_WIDTH);
	y = data->draw_start;
	while (y <= data->draw_end)
	{
		tex_y = ((y - data->draw_start) * IMG_WIDTH) / (data->draw_end - data->draw_start);
		color = get_texture_pixel(texture, tex_x, tex_y);
		mlx_pixel_put(data->mlx, data->win, x, y, color);
		y++;
	}
}
