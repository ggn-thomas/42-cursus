/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:33:37 by thomas            #+#    #+#             */
/*   Updated: 2024/11/14 14:44:53 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	*count += write(1, &c, 1);
}

static int	ft_check(const char *str, va_list args, int i, int count)
{
	if (str[i + 1] == 'c')
		ft_putchar(va_arg(args, int), &count);
	if (str[i + 1] == 's')
		ft_putstr(va_arg(args, char *), &count);
	if (str[i + 1] == 'd' || str[i + 1] == 'i')
		ft_putnbr(va_arg(args, int), &count);
	if (str[i + 1] == 'x')
		ft_uputnbr_base(va_arg(args, unsigned int), "0123456789abcdef", &count);
	if (str[i + 1] == 'X')
		ft_uputnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF", &count);
	if (str[i + 1] == 'p')
		ft_putnbr_adress(va_arg(args, unsigned long int), &count);
	if (str[i + 1] == 'u')
		ft_uputnbr_base(va_arg(args, unsigned int), "0123456789", &count);
	if (str[i + 1] == '%')
		ft_putchar('%', &count);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args ;
	int		i;
	int		count;
	int		len;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_check(format, args, i, count);
			i++;
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
