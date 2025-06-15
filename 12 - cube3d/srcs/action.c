/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:45:18 by thgaugai          #+#    #+#             */
/*   Updated: 2025/06/15 12:11:33 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_forward(t_player *player)
{
	if (data->map[(int)player->y]->line[(int)(player->x + player->dir_x * player->move_speed)] == 0)
		player->x += player->dir_x * player->move_speed;
	if (data->map[(int)(player->y + player->dir_y * player->move_speed)]->line[(int)player->x] == 0)
		player->y += player->dir_y * player->move_speed;
}

/*
void	ft_keypress(int keycode, t_data *data)
{
	if (keycode == 65307)//esc
	{
		exit(EXIT_SUCCESS);
	}
	else if (keycode == 13)//w
	else if (keycode == 1)//s
	else if (keycode == 0)//a
	else if (keycode == 2)//d
	else if (keycode == 123)//flèche gauche
	else if (keycode == 124)// " droite

}*/