/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:09:57 by thomas            #+#    #+#             */
/*   Updated: 2024/12/18 18:20:54 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_valid_syntax(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '+' || str[i][j] == '-')
			{
				if (!(str[i][j + 1] >= '0' && str[i][j + 1] <= '9'))
					return (0);
			}
			else if (!(str[i][j] >= '0' && str[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_double(t_stack_node **lst, int nbr)
{
	t_stack_node	*index;

	if (!(*lst))
		return (0);
	index = *lst;
	while (index)
	{
		if (index->nbr == nbr)
			return (1);
		index = index->next;
	}
	return (0);
}

void	ft_free_stack(t_stack_node **lst)
{
	t_stack_node	*tmp;

	if (!lst || !*lst)
		return ;
	while ((*lst)->next != NULL)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	free(*lst);
	*lst = NULL;
}

void	ft_free_split(char **str)
{
	int	i;

	if (!str || !*str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_error(char **str, t_stack_node **lst)
{
	write(1, "Error\n", 6);
	ft_free_split(str);
	ft_free_stack(lst);
}
