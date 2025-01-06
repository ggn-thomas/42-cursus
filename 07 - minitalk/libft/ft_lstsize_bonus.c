/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:05:42 by thomas            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/11/09 11:59:26 by thomas           ###   ########.fr       */
=======
/*   Updated: 2024/10/16 13:46:11 by thomas           ###   ########.fr       */
>>>>>>> 7925e06 (initial commit 42)
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
<<<<<<< HEAD
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
=======
	t_list	*temp;

	temp = lst;
	i = 0;
	while (temp)
	{
		temp = temp->next;
>>>>>>> 7925e06 (initial commit 42)
		i++;
	}
	return (i);
}
