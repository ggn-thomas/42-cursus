/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:23:31 by thomas            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/16 14:53:14 by thomas           ###   ########.fr       */
=======
/*   Updated: 2024/10/21 16:39:23 by thgaugai         ###   ########.fr       */
>>>>>>> 7925e06 (initial commit 42)
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
<<<<<<< HEAD
=======
	if (!lst || !del)
		return ;
>>>>>>> 7925e06 (initial commit 42)
	del(lst->content);
	free(lst);
}
