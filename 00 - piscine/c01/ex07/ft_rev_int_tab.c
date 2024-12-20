/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:09:51 by thgaugai          #+#    #+#             */
/*   Updated: 2024/07/13 19:14:17 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_rev_int_tab(int *tab, int size)
{
	int	i ;
	int	temp ;

	i = 0;
	temp = 0;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size -1 - i];
		tab[size - 1 - i] = temp;
		i++;
	}
}
