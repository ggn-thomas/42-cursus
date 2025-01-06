/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:54:07 by thomas            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/17 16:49:18 by thomas           ###   ########.fr       */
=======
/*   Updated: 2024/10/21 16:40:17 by thgaugai         ###   ########.fr       */
>>>>>>> 7925e06 (initial commit 42)
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
<<<<<<< HEAD

=======
	
	if (!lst || !del)
		return ;
>>>>>>> 7925e06 (initial commit 42)
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	free(*lst);
	*lst = NULL;
}
