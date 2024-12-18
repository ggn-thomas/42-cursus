/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:21:05 by thomas            #+#    #+#             */
/*   Updated: 2024/12/18 18:21:23 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_check_order(t_stack_node **lst)
{
	t_stack_node	*tmp;
	t_stack_node	*tmp_next;

	tmp = *lst;
	while (tmp->next)
	{
		tmp_next = tmp->next;
		if (tmp->nbr > tmp_next->nbr)
			return (0);
		tmp = tmp_next;
	}
	return (1);
}

void	ft_find_target_node(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*index_a;
	t_stack_node	*index_b;
	t_stack_node	*target_node;
	long			best_value;

	index_b = *stack_b;
	while (index_b)
	{
		best_value = LONG_MAX;
		index_a = *stack_a;
		while (index_a)
		{
			if (index_a->nbr > index_b->nbr && index_a->nbr < best_value)
			{
				best_value = index_a->nbr;
				target_node = index_a;
			}
			index_a = index_a->next;
		}
		if (best_value == LONG_MAX)
			index_b->target_node = ft_smallest(stack_a);
		else
			index_b->target_node = target_node;
		index_b = index_b->next;
	}
}

t_stack_node	**ft_push_price(t_stack_node **lst)
{
	size_t			median;
	size_t			i;
	size_t			j;
	t_stack_node	*tmp;
	size_t			len;

	len = ft_lstlen(lst);
	tmp = *lst;
	median = len / 2;
	i = 0;
	while (i++ <= median)
	{
		tmp->push_price = i;
		tmp->above_median = true;
		tmp = tmp->next;
	}
	j = len - median;
	while (tmp)
	{
		tmp->push_price = j;
		tmp->above_median = false;
		tmp = tmp->next;
		j--;
	}
	return (lst);
}

static void	finish_sort(t_stack_node **lst)
{
	t_stack_node	*smallest;

	ft_push_price(lst);
	smallest = ft_smallest(lst);
	while (*lst != smallest)
	{
		if (smallest->above_median)
			ra(lst);
		else
			rra(lst);
	}
}

t_stack_node	**ft_push_swap(t_stack_node **stack_a, t_stack_node **stack_b)
{
	size_t	len;

	len = ft_lstlen(stack_a);
	if (ft_check_order(stack_a) || len == 1)
		return (stack_a);
	else if (len == 2)
		ft_sort_2(stack_a);
	else if (len == 3)
		ft_sort_3(stack_a);
	else
	{
		while (len != 2)
		{
			pb(stack_a, stack_b);
			len--;
		}
		while (*stack_b)
		{
			stack_init(stack_a, stack_b);
			stack_moves(stack_a, stack_b);
		}
		finish_sort(stack_a);
	}
	return (stack_a);
}
