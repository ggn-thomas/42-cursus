/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:03:11 by thomas            #+#    #+#             */
/*   Updated: 2024/12/18 18:18:37 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "X11/X.h"
# include "X11/Xlib.h"
# include <stdlib.h>
# include <unistd.h>
# define IMG_WIDTH 40
# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define RESET "\033[0m"

typedef struct s_stack_line
{
	char				*str;
	struct s_stack_line	*next;
	struct s_stack_line	*prev;
}						t_stack_line;

typedef struct s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct s_data
{
	void				*mlx;
	void				*win;
	void				*wall;
	void				*exit;
	void				*empty;
	void				*player;
	void				*player_left;
	void				*enemy;
	void				*collectible;
	void				*counter;
	char				**map;
	int					map_width;
	int					map_lenght;
	int					count;
	int					nb_exit;
	int					count_key;
	t_point				player_position;
	t_point				exit_position;
}						t_data;

char					*ft_strdup(const char *s);
char					**map_init(char *param);
void					ft_free_stack(t_stack_line **lst);
void					ft_free_tab(char **tab);
int						ft_exit(t_data *data);
int						ft_lstlen(t_stack_line **lst);
t_stack_line			*ft_lst_last(t_stack_line **map);
int						ft_count_element_stack(t_stack_line **map, char c);
int						ft_count_element_tab(char **map, char c);
t_point					find_start_position(char **map, char c);
int						count_column(char **map);
int						count_rows(char **map);
void					display_win(void);
void					display_lose(void);
int						ft_parsing(t_stack_line **map);
int						flood_fill(char **cpy_map);
void					window_init(char **map);
void					draw_map(t_data *data);
void					draw_background(t_data *data);
void					display_nb_key_press(t_data *data);
void					draw_counter(t_data *data);
void					player_moves_left(int x, int y, t_data *data);
void					player_moves_right(int x, int y, t_data *data);
int						check_len_map(t_stack_line **map);

#endif