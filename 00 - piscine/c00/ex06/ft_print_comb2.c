/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:37:41 by thgaugai          #+#    #+#             */
/*   Updated: 2024/07/11 13:50:01 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	char	nb1 ;
	char	nb2 ;

	nb1 = 0;
	nb2 = nb1 + 1;
	while (nb1 < 99)
	{
		while (nb2 < 100)
		{
			if (nb1 < nb2)
			{
				ft_putchar(nb1 / 10 + '0');
				ft_putchar(nb1 % 10 + '0');
				write(1, " ", 1);
				ft_putchar(nb2 / 10 + '0');
				ft_putchar(nb2 % 10 + '0');
				if (!(nb1 == 98 && nb2 == 99))
					write(1, ", ", 2);
			}
			nb2++;
		}
		nb1++;
		nb2 = 0;
	}
}
