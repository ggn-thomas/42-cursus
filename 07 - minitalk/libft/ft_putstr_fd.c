/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:21:32 by thgaugai          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/15 12:25:45 by thgaugai         ###   ########.fr       */
=======
/*   Updated: 2024/10/18 10:12:47 by thgaugai         ###   ########.fr       */
>>>>>>> 7925e06 (initial commit 42)
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
<<<<<<< HEAD
	while (*s)
	{
		write(fd, s, 1);
		s++;
=======
	int	i;

	if (!s || fd < 0)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
>>>>>>> 7925e06 (initial commit 42)
	}
}
