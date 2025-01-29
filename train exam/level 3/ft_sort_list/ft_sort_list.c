/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:55:07 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/29 10:17:16 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int	tmp;
	t_list	*first;

	first = lst;
	while (lst && lst->next)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)
		{
			tmp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = tmp;
			lst = first;
		}
		else
			lst = lst->next;
	}
	lst = first;
	return (lst);
}

#include <stdio.h>
#include <stdlib.h>

int ascending(int a, int b)
{
	return (a <= b);
}
void	ft_print(t_list **begin_list)
{
	t_list	*current;

	current = *begin_list;
	while (current)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
}

int	main(void)
{
	t_list	*nbr1;
	nbr1 = malloc(sizeof(t_list));
	nbr1->data = 5;
	nbr1->next = 0;

	t_list	*nbr2;
	nbr2 = malloc(sizeof(t_list));
	nbr2->data = 10;
	nbr2->next = 0;

	t_list	*nbr3;
	nbr3 = malloc(sizeof(t_list));
	nbr3->data = 1000000;
	nbr3->next = 0;

	t_list	*nbr4;
	nbr4 = malloc(sizeof(t_list));
	nbr4->data = 563;
	nbr4->next = 0;

	nbr1->next = nbr2;
	nbr2->next = nbr3;
	nbr3->next = nbr4;

	t_list	**begin_list = &nbr1;
	t_list	*result;
	result = sort_list(*begin_list, ascending);
	ft_print(&result);
}
