/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_in_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:38:58 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/10 10:05:46 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sort_in_tab(int *tab, unsigned int size)
{
	unsigned int	j;
	unsigned int	i;

	i = 0;
	j = 0;
	while (i <= size)
	{
		j = 0;
		while (j < size)
		{
			if (tab[j] > tab[j + 1])
				ft_swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < size)
	{
		printf(" %d |", tab[i]);
		i++;
	}
	printf("\n%d\n", i);
}

int	main(void)
{
	int	tab[10] = {5, 155, 789, 1, 7, 39, 44, 6, 1000, 22};

	sort_in_tab(tab, 10);
}
