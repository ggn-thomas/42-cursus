/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:11:56 by thgaugai          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/15 12:20:06 by thgaugai         ###   ########.fr       */
=======
/*   Updated: 2024/10/18 10:11:32 by thgaugai         ###   ########.fr       */
>>>>>>> 7925e06 (initial commit 42)
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
<<<<<<< HEAD
=======
	if (fd < 0)
		return ;
>>>>>>> 7925e06 (initial commit 42)
	write(fd, &c, 1);
}
