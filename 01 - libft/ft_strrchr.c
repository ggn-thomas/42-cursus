/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:31:17 by thgaugai          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/17 16:16:43 by thomas           ###   ########.fr       */
=======
/*   Updated: 2024/10/17 18:11:35 by thgaugai         ###   ########.fr       */
>>>>>>> 7925e06 (initial commit 42)
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	s += i;
<<<<<<< HEAD
=======
	if (*s == '\0' && c == '\0')
		return ((char *)s);
>>>>>>> 7925e06 (initial commit 42)
	while (i >= 0)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s--;
		i--;
	}
<<<<<<< HEAD
	if (*s == '\0' && c == '\0')
		return ((char *)s);
=======
>>>>>>> 7925e06 (initial commit 42)
	return (NULL);
}
