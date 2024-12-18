/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entritoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:59:36 by thgaugai          #+#    #+#             */
/*   Updated: 2024/08/01 15:28:00 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
int	ft_intlen(int nb)
{
	int	i ;

	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nb)
{
	int	i;
	int	len;
	char	*result;
	int	is_negative;
	
	len = ft_intlen(nb);
	result = malloc(sizeof(char) * len + 1);
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	if (nb == -2147483648)
	{
		result = "-2147483648";
		return (result);
	}
	is_negative = 0;
	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		is_negative = 1;
	}
	i = len - 1;
	if (nb == 0)
		result[i] = '0';
	else 
	{
		while (nb != 0)
		{
			result[i--] = (nb % 10) + '0';
			nb /= 10;
		}
	}
	if (is_negative == 1)
		result[0] = '-';
	return (result);
}
#include <stdio.h>
int	main()
{
	char	*result;

	result = ft_itoa(21483648);
	printf("%s\n", result);
}

