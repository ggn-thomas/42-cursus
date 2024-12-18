/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:34:52 by thomas            #+#    #+#             */
/*   Updated: 2024/12/18 18:20:32 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_push(t_stack_node **lst_src, t_stack_node **lst_dest)
{
	t_stack_node	*new_node;

	if (!*lst_src)
		return ;
	new_node = *lst_src;
	*lst_src = (*lst_src)->next;
	if (*lst_src)
		(*lst_src)->prev = NULL;
	new_node->prev = NULL;
	if (!(*lst_dest))
	{
		*lst_dest = new_node;
		new_node->next = NULL;
	}
	else
	{
		new_node->next = *lst_dest;
		new_node->next->prev = new_node;
		*lst_dest = new_node;
	}
}

void	pa(t_stack_node **lst_src, t_stack_node **lst_dest)
{
	ft_push(lst_src, lst_dest);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **lst_src, t_stack_node **lst_dest)
{
	ft_push(lst_src, lst_dest);
	write(1, "pb\n", 3);
}
