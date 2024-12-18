/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:45:14 by thgaugai          #+#    #+#             */
/*   Updated: 2024/07/22 17:50:00 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i ;

	i = nb - 1;
	if (nb == 1)
		return (0);
	if (nb <= 0)
		return (0);
	while (i > 1)
	{
		if (nb % i == 0)
			return (0);
		else
			i--;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb))
		return (nb);
	else
		while (!(ft_is_prime(nb)))
			nb += 1;
	return (nb);
}
