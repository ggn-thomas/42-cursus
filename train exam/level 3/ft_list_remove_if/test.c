/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:11:04 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/29 09:49:31 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_lst_new(void *data)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lst_add_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

int	cmp(void *a, void *b)
{
	if (*(int*)a == *(int *)b)
		return (0);
	else
		return (1);
}

#include <stdio.h>
/*
int	main(void)
{
	int	tab[10] = {1, 5, 89, 5, 6, 789, 5, 63, 42, 1};
	int	i;
	int	*data_ref = malloc(sizeof(int));
	t_list	*tmp;
	t_list	*lst = NULL;

	data_ref[0] = 5;
	i = 0;
	while (tab[i])
	{
		int	*data = malloc(sizeof(int));
		*data = tab[i];
		tmp = ft_lst_new(data);
		ft_lst_add_front(&lst, tmp);
		printf("%d\n", *(int *)tmp->data);
		i++;
	}
	ft_list_remove_if(&lst, &data_ref, cmp);
	tmp = lst;
	while (tmp)
	{
		printf("%d\n", *(int *)tmp->data);
		tmp = tmp->next;
	}
	return (0);
}*/

int	main(void)
{
	int	tab[10] = {1, 5, 89, 5, 6, 789, 5, 63, 42, 1};
	int	i;
	int	*data_ref;
	t_list	*tmp;
	t_list	*lst;

	data_ref = malloc(sizeof(int));
	if (!data_ref)
		return (1);
	*data_ref = 5;
	lst = NULL;
	i = 0;
	while (i < 10)  // Changed condition to i < 10
	{
		int *data = malloc(sizeof(int));  // Nouvelle allocation pour chaque nœud
		if (!data)
			continue;
		*data = tab[i];
		tmp = ft_lst_new(data);
		if (tmp)
			ft_lst_add_front(&lst, tmp);
		printf("%d\n", *(int *)tmp->data);
		i++;
	}
	ft_list_remove_if(&lst, data_ref, cmp);
	tmp = lst;
	printf("-------------------------------------------------");
	while (tmp)
	{
		printf("%d\n", *(int *)tmp->data);
		tmp = tmp->next;
	}
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp->data);
		free(tmp);
	}
	free(data_ref);
	return (0);
}