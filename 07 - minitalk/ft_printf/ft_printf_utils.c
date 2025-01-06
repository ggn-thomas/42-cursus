/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:47:30 by thomas            #+#    #+#             */
/*   Updated: 2024/12/16 14:15:52 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *count)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)", count);
		return ;
	}
	while (str[i])
	{
		*count += write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int n, int *count)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", count);
		return ;
	}
	else if (n < 0)
	{
		n *= -1;
		ft_putchar('-', count);
		ft_putnbr(n, count);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10, count);
		ft_putnbr(n % 10, count);
	}
	else
		ft_putchar(n + '0', count);
}

size_t	ft_sstrlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_uputnbr_base(unsigned long int n, char *base, int *count)
{
	unsigned int	len;

	len = ft_sstrlen(base);
	if (n >= len)
	{
		ft_uputnbr_base(n / len, base, count);
		ft_uputnbr_base(n % len, base, count);
	}
	else
		ft_putchar(base[n], count);
}

void	ft_putnbr_adress(unsigned long int n, int *count)
{
	if (n == 0)
	{
		ft_putstr("(nil)", count);
		return ;
	}
	ft_putstr("0x", count);
	ft_uputnbr_base(n, "0123456789abcdef", count);
}
