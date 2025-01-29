/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:31:43 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/29 10:46:01 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	fprime(int nb)
{
	int	prime;

	prime  = 0;
	if (nb == 1)
	{
		printf("1");
	}
	else
	{
		prime = 2;
		while (nb > 1)
		{
			if (nb % prime == 0)
			{
				printf("%d", prime);
				nb/=prime;
				if (nb > 1)
					printf("*");
				prime--;
			}
		prime++;
		}
	}
	printf("\n");
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	result = 0;
	i = 0;
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("\n");
		return (1);
	}
	int nb = ft_atoi(av[1]);
	fprime(nb);
	return (0);
}