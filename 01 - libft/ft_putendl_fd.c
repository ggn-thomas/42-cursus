/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:26:54 by thgaugai          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/15 12:30:47 by thgaugai         ###   ########.fr       */
=======
/*   Updated: 2024/10/18 10:24:59 by thgaugai         ###   ########.fr       */
>>>>>>> 7925e06 (initial commit 42)
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
<<<<<<< HEAD
	while (*s)
	{
		write(fd, s, 1);
		s++;
=======
	int	i;

	i = 0;
	if (!s || fd < 0)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
>>>>>>> 7925e06 (initial commit 42)
	}
	write(fd, "\n", 1);
}
