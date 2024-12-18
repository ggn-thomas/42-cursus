/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:56:43 by thomas            #+#    #+#             */
/*   Updated: 2024/12/18 18:20:38 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_reverse_rotate(t_stack_node **lst)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	first = *lst;
	last = ft_lst_last(lst);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*lst = last;
	ft_update_index(lst);
}

void	rra(t_stack_node **lst)
{
	ft_reverse_rotate(lst);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **lst)
{
	ft_reverse_rotate(lst);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
