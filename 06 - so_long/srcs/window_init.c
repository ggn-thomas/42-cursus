/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:18:41 by thgaugai          #+#    #+#             */
/*   Updated: 2024/12/18 12:05:02 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../includes/so_long.h"

static void	load_sprites(t_data *data)
{
	int	w;

	w = IMG_WIDTH;
	data->wall = mlx_xpm_file_to_image(data->mlx, "sprites/wall.xpm", &w, &w);
	data->exit = mlx_xpm_file_to_image(data->mlx, "sprites/exit.xpm", &w, &w);
	data->player = mlx_xpm_file_to_image(data->mlx, "sprites/player.xpm", &w,
			&w);
	data->empty = mlx_xpm_file_to_image(data->mlx, "sprites/empty.xpm", &w, &w);
	data->collectible = mlx_xpm_file_to_image(data->mlx,
			"sprites/collectible.xpm", &w, &w);
	data->counter = mlx_xpm_file_to_image(data->mlx, "sprites/counter.xpm", &w,
			&w);
	data->player_left = mlx_xpm_file_to_image(data->mlx,
			"sprites/player_left.xpm", &w, &w);
	data->enemy = mlx_xpm_file_to_image(data->mlx, "sprites/ennemi.xpm", &w,
			&w);
}

static int	close_window(t_data *data)
{
	ft_exit(data);
	exit(EXIT_SUCCESS);
	return (0);
}

static int	key_press(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		ft_exit(data);
		exit(0);
	}
	else if (keycode == 119)
		player_moves_left(0, -1, data);
	else if (keycode == 115)
		player_moves_right(0, 1, data);
	else if (keycode == 97)
		player_moves_left(-1, 0, data);
	else if (keycode == 100)
		player_moves_right(1, 0, data);
	return (0);
}

void	window_init(char **map)
{
	t_data	data;

	data.map = map;
	data.map_width = count_column(map);
	data.map_lenght = count_rows(map);
	data.player_position = find_start_position(map, 'P');
	data.exit_position = find_start_position(map, 'E');
	data.count_key = 0;
	data.count = 0;
	data.nb_exit = ft_count_element_tab(data.map, 'C');
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		write(1, "Error initializing MiniLibx\n", 29);
		return ;
	}
	data.win = mlx_new_window(data.mlx, data.map_width * IMG_WIDTH,
			data.map_lenght * IMG_WIDTH, "so_long");
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	load_sprites(&data);
	draw_background(&data);
	draw_map(&data);
	draw_counter(&data);
	mlx_loop(data.mlx);
}
