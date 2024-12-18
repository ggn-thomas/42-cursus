/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:52:06 by thomas            #+#    #+#             */
/*   Updated: 2024/12/18 18:20:42 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_rotate(t_stack_node **lst)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	first = *lst;
	last = ft_lst_last(lst);
	*lst = first->next;
	if (*lst)
		(*lst)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	ft_update_index(lst);
}

void	ra(t_stack_node **lst)
{
	ft_rotate(lst);
	write(1, "ra\n", 3);
}

void	rb(t_stack_node **lst)
{
	ft_rotate(lst);
	write(1, "rb\n", 3);
}

void	rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write(1, "rr\n", 3);
}
