/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:36:49 by thgaugai          #+#    #+#             */
/*   Updated: 2024/12/18 18:21:11 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack_node	**ft_sort_2(t_stack_node **lst)
{
	t_stack_node	*next;

	next = (*lst)->next;
	if ((*lst)->nbr > next->nbr)
		sa(lst);
	return (lst);
}

t_stack_node	**ft_sort_3(t_stack_node **lst)
{
	t_stack_node	*biggest;
	t_stack_node	*smallest;

	biggest = ft_biggest(lst);
	smallest = ft_smallest(lst);
	if (biggest->index == 2)
		sa(lst);
	else if (biggest->index == 1 && smallest->index == 2)
		rra(lst);
	else if (biggest->index == 0 && smallest->index == 1)
		ra(lst);
	else if (biggest->index == 0 && smallest->index == 2)
	{
		sa(lst);
		rra(lst);
	}
	else if (biggest->index == 1 && smallest->index == 0)
	{
		sa(lst);
		ra(lst);
	}
	return (lst);
}
