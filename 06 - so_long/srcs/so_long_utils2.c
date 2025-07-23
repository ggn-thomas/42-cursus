/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:08:25 by thomas            #+#    #+#             */
/*   Updated: 2024/12/18 09:33:47 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../includes/so_long.h"

int	count_column(char **map)
{
	int	x;

	x = 0;
	while (map[0][x])
		x++;
	return (x);
}

int	count_rows(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	ft_lstlen(t_stack_line **lst)
{
	int				i;
	t_stack_line	*tmp;

	i = 0;
	tmp = (*lst);
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	display_win(void)
{
	ft_printf(GREEN);
	ft_printf("\ndb   d8b   db d888888b d8b   db \n");
	ft_printf("88   I8I   88   `88'   888o  88\n");
	ft_printf("88   I8I   88    88    88V8o 88\n");
	ft_printf("Y8   I8I   88    88    88 V8o88\n");
	ft_printf("`8b d8'8b d8'   .88.   88  V888\n");
	ft_printf(" `8b8' `8d8'  Y888888P VP   V8P\n");
	ft_printf(RESET);
}

void	display_lose(void)
{
	ft_printf(RED);
	ft_printf("\ndb       .d88b.  .d8888. d88888b \n");
	ft_printf("88      .8P  Y8. 88'  YP 88'     \n");
	ft_printf("88      88    88 `8bo.   88ooooo \n");
	ft_printf("88      88    88   `Y8b. 88~~~~~ \n");
	ft_printf("88booo. `8b  d8' db   8D 88.      \n");
	ft_printf("Y88888P  `Y88P'  `8888Y' Y88888P \n");
	ft_printf(RESET);
}
