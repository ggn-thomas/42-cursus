/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:47:20 by thgaugai          #+#    #+#             */
/*   Updated: 2025/06/12 17:49:09 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../gnl/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include "X11/X.h"
# include "X11/Xlib.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define IMG_WIDTH 40

typedef struct s_param_map
{
	char	**map;
	int		length;
	int		width;
}			t_param_map;

typedef struct s_map
{
	char	*line;
	struct s_map	*next;
}			t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_map	**map;
	void	*NO;
	void	*SO;
	void	*WE;
	void	*EA;
	int		C[3];
	int		F[3];
	int		size_x;
	int		size_y;
}			t_data;

void		error(char *mess);
// void	ft_keypress(int keycode, t_data *data);
t_map		*ft_new_node(char *line);
void		ft_lstadd_back(t_map **lst, t_map *new);
int	window_init(t_param_map *map);

#endif