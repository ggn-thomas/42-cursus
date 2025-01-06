/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:00:30 by thgaugai          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/15 12:10:39 by thgaugai         ###   ########.fr       */
=======
/*   Updated: 2024/10/21 16:53:10 by thgaugai         ###   ########.fr       */
>>>>>>> 7925e06 (initial commit 42)
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;
<<<<<<< HEAD

=======
	
	if (!s || !f)
		return ;
>>>>>>> 7925e06 (initial commit 42)
	i = -1;
	while (s[++i])
		f(i, &s[i]);
}
