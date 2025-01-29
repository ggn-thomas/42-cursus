/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:00:32 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/29 15:02:09 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*first;

	first = begin_list;
	while (first)
	{
		(*f)(first->data);
		first = first->next;
	}
}
