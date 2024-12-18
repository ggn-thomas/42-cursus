/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:22:50 by thgaugai          #+#    #+#             */
/*   Updated: 2024/12/18 18:20:59 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack_node	*ft_lst_last(t_stack_node **lst)
{
	t_stack_node	*tmp;

	if (!*lst)
		return (NULL);
	tmp = (*lst);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	ft_lstlen(t_stack_node **lst)
{
	int				i;
	t_stack_node	*tmp;

	i = 0;
	tmp = (*lst);
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_update_index(t_stack_node **lst)
{
	int				i;
	t_stack_node	*tmp;

	i = 0;
	tmp = (*lst);
	while (tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}

t_stack_node	*ft_smallest(t_stack_node **lst)
{
	t_stack_node	*tmp;
	t_stack_node	*smallest;

	tmp = *lst;
	smallest = (*lst)->next;
	while (tmp)
	{
		if (tmp->nbr < smallest->nbr)
			smallest = tmp;
		tmp = tmp->next;
	}
	return (smallest);
}

t_stack_node	*ft_biggest(t_stack_node **lst)
{
	t_stack_node	*tmp;
	t_stack_node	*biggest;

	tmp = *lst;
	biggest = (*lst)->next;
	while (tmp)
	{
		if (tmp->nbr > biggest->nbr)
			biggest = tmp;
		tmp = tmp->next;
	}
	return (biggest);
}
