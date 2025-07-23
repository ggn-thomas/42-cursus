/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:51:56 by thgaugai          #+#    #+#             */
/*   Updated: 2024/12/18 18:21:19 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack_node	*find_cheapest(t_stack_node **lst)
{
	t_stack_node	*index;
	t_stack_node	*cheapest;
	int				best_price;
	int				total;

	total = 0;
	best_price = 2147483647;
	index = *lst;
	while (index)
	{
		total = index->push_price + index->target_node->push_price;
		if (total < best_price)
		{
			best_price = total;
			cheapest = index;
		}
		index = index->next;
	}
	cheapest->cheapest = true;
	return (cheapest);
}

static void	rotate_both(t_stack_node **stack_a, t_stack_node **stack_b,
		t_stack_node *cheapest)
{
	while (*stack_a != cheapest->target_node && *stack_b != cheapest)
		rr(stack_a, stack_b);
	ft_update_index(stack_a);
	ft_update_index(stack_b);
}

static void	reverse_rotate_both(t_stack_node **stack_a, t_stack_node **stack_b,
		t_stack_node *cheapest)
{
	while (*stack_a != cheapest->target_node && *stack_b != cheapest)
		rrr(stack_a, stack_b);
	ft_update_index(stack_a);
	ft_update_index(stack_b);
}

static void	finish_rotation(t_stack_node **lst, t_stack_node *top_node,
		char stack_name)
{
	while (*lst != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(lst);
			else
				rra(lst);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(lst);
			else
				rrb(lst);
		}
	}
}

void	stack_moves(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*cheapest;

	cheapest = find_cheapest(stack_b);
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_both(stack_a, stack_b, cheapest);
	else if (!(cheapest->above_median)
		&& !(cheapest->target_node->above_median))
		reverse_rotate_both(stack_a, stack_b, cheapest);
	finish_rotation(stack_a, cheapest->target_node, 'a');
	finish_rotation(stack_b, cheapest, 'b');
	pa(stack_b, stack_a);
}
