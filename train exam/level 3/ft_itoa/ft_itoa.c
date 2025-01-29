/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:48:22 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/29 11:03:48 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_intlen(nbr)
{
	int	count = 0;

	if (nbr < 0)
	{
		nbr *= -1;
		count++;
	}
	if (nbr < 10)
		return (1);
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);

}

char	*ft_itoa(int nbr)
{
	int	len;
	char	*result;

	len = ft_intlen(nbr);
	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	result[0] = '0';
	if (nbr < 0)
	{
		nbr *= -1;
		result[0] = '-';
	}
	int i = len - 1;
	while (nbr != 0)
	{
		result[i] = (nbr % 10) + '0';
		nbr /= 10;
		i--;
	}
	result[len] = '\0';
	return (result);
}
