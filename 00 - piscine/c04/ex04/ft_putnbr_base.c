/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:58:49 by thgaugai          #+#    #+#             */
/*   Updated: 2024/07/21 19:10:01 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	int_mini(unsigned int nbr, char *base)
{
	unsigned int	lenght ;

	lenght = ft_strlen(base);
	if (nbr >= lenght)
	{
		int_mini(nbr / lenght, base);
		int_mini(nbr % lenght, base);
	}
	else
		ft_putchar(base[nbr]);
}

char	error(char *base)
{
	int	i ;
	int	j ;
	int	lenght ;

	lenght = ft_strlen(base);
	i = 0;
	if ((lenght == 0) || (lenght == 1))
		return (0);
	while (base[i])
	{
		if ((base[i] == '+') || (base[i] == '-'))
			return (0);
		else
		{
			j = 1;
			while (base[j])
			{
				if (base[i] == base[j] && i != j)
					return (0);
				j++;
			}
			i++;
		}
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	lenght ;

	if (!error(base))
		return ;
	lenght = ft_strlen(base);
	if (nbr == -2147483648)
	{
		nbr = nbr * -1;
		ft_putchar('-');
		int_mini(nbr, base);
		return ;
	}
	if (nbr < 0)
	{
		nbr = nbr * -1;
		ft_putchar('-');
		ft_putnbr_base(nbr, base);
	}
	else if (nbr >= lenght)
	{
		ft_putnbr_base(nbr / lenght, base);
		ft_putnbr_base(nbr % lenght, base);
	}
	else
		ft_putchar(base[nbr]);
}
