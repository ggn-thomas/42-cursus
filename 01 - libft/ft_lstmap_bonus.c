/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:20:02 by thomas            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/17 17:08:56 by thomas           ###   ########.fr       */
=======
/*   Updated: 2024/10/18 09:46:00 by thgaugai         ###   ########.fr       */
>>>>>>> 7925e06 (initial commit 42)
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	t_list	*list;
	t_list	*obj;
<<<<<<< HEAD
=======
	void	*content;
>>>>>>> 7925e06 (initial commit 42)

	if (!lst || !f || !del)
		return (NULL);
	list = NULL;
	while (lst)
	{
<<<<<<< HEAD
		obj = ft_lstnew(f(lst->content));
		if (!obj)
		{
=======
		content = f(lst->content);
		if (content)
			obj = ft_lstnew(content);
		if (!obj || !content)
		{
			if (content)
				del(content);
>>>>>>> 7925e06 (initial commit 42)
			ft_lstclear(&list, del);
			return (NULL);
		}
		ft_lstadd_back(&list, obj);
		lst = lst->next;
	}
	return (list);
}
