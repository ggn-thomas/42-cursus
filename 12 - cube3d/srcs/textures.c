/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:08:50 by thomas            #+#    #+#             */
/*   Updated: 2025/06/16 17:11:41 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"


void    *get_wall_texture(t_data *data, t_ray *ray)
{
    if (ray->side == 0)
    {
        if (ray->dir_x > 0)
            return (data->EA);
        else
            return (data->WE);
    }
    else
    {
        if (ray->dir_y > 0)
            return (data->SO);
        else
            return (data->NO);
    }
}