/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:11:11 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/13 09:40:56 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_intlen(long nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		nbr++;
	if (nbr < 0)
	{
		nbr *= -1;
		count++;
	}
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int nbr)
{
	char	*result;
	long	nbr_long;
	int	i;
	int	len;

	nbr_long = nbr;
	len = ft_intlen(nbr_long);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[0] = '0';// si jamais nbr = 0
	if (nbr_long < 0)
	{
		nbr_long *= - 1;
		result[0] = '-';
	}
	i = len - 1;
	while (nbr_long != 0)
	{
		result[i--] = (nbr_long % 10) + '0';
		nbr_long /= 10;
	}
	result[len] = '\0';
	return (result);

}


int	main(int ac, char *av[])
{
	printf("%s", ft_itoa(0));
	return (0);
}