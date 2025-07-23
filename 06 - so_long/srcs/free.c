/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:52:46 by thomas            #+#    #+#             */
/*   Updated: 2024/12/18 09:33:28 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_stack(t_stack_line **lst)
{
	t_stack_line	*tmp;

	if (!lst || !*lst)
		return ;
	while ((*lst)->next != NULL)
	{
		tmp = (*lst)->next;
		free((*lst)->str);
		free(*lst);
		*lst = tmp;
	}
	free((*lst)->str);
	free(*lst);
	*lst = NULL;
}

void	ft_free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	destroy_sprites(t_data *data)
{
	mlx_destroy_image(data->mlx, data->collectible);
	mlx_destroy_image(data->mlx, data->player);
	mlx_destroy_image(data->mlx, data->player_left);
	mlx_destroy_image(data->mlx, data->exit);
	mlx_destroy_image(data->mlx, data->empty);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->counter);
	mlx_destroy_image(data->mlx, data->enemy);
}

int	ft_exit(t_data *data)
{
	destroy_sprites(data);
	mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	ft_free_tab(data->map);
	free(data->mlx);
	exit(0);
	return (0);
}
