/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:39:00 by thomas            #+#    #+#             */
/*   Updated: 2024/12/18 18:20:46 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_swap(t_stack_node **lst)
{
	t_stack_node	*first;
	t_stack_node	*second;

	first = *lst;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	second->index -= 1;
	first->index += 1;
	*lst = second;
}

void	sa(t_stack_node **lst)
{
	ft_swap(lst);
	write(1, "sa\n", 3);
}

void	sb(t_stack_node **lst)
{
	ft_swap(lst);
	write(1, "sb\n", 3);
}

void	ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	write(1, "ss\n", 3);
}
