/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:30:04 by thgaugai          #+#    #+#             */
/*   Updated: 2024/07/17 11:44:44 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	conv_hex(unsigned char c)
{
	char	*tab;

	tab = "0123456789abcdef";
	ft_putchar('\\');
	ft_putchar(tab[c / 16]);
	ft_putchar(tab[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i ;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
			conv_hex((unsigned char) str[i]);
		else
			ft_putchar(str[i]);
		i++;
	}
}
