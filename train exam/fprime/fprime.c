/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:26:31 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/22 13:01:03 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	fprime(unsigned int nb)
{
	unsigned int	prime;

	if (nb == 1)
		printf("1");
	else
	{
		prime = 2;// 2 est le + petit nb premier
		while (nb > 1)
		{
			if (nb % prime == 0)
			{
				printf("%d", prime);
				nb /= prime;
				if (nb > 1)
					printf("*");
				prime--;
			}
			prime++;
		}
	}
}

/*
- je vérifie si le nb est égale à 1
- sinon -> je commence avec 2 (le + petit nb premier)
- boucle tant que le nb est supérieur à 1
- si nb % prime = 0, alors c'est un nb premier donc je l'affiche
- je divise le nb par le nb premier
- si le nb est supérieur à 1 -> "*"
- je décremente prime


*/

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("\n");
		return (0);
	}
	fprime(av[1]);
	return (0);
}

void	fprime(unsigned int nb)
{
	unsigned int	prime;

	if (nb == 1)
		printf("1");
	else
	{
		prime = 2;
		while (nb > 1)
		{
			if (nb % prime == 0)
			{
				printf("%d", prime);
				nb /= prime;
				if (nb > 1)
					printf("*");
				prime--;
			}
			prime++;
		}
	}
}