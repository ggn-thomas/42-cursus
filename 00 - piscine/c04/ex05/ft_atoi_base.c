/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:43:04 by thgaugai          #+#    #+#             */
/*   Updated: 2024/07/25 10:15:46 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int	ft_strlen(char *str)
{
	int	i ;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	error(char *base)
{
	int	i ;
	int	j ;
	int	lenght ;

	lenght = ft_strlen(base);
	if (lenght == 0 || lenght == 1)
		return (0);
	i = 0;
	while (base[i])
	{
		if ((base[i] == '+') || (base[i] == '-'))
			return (0);
		else
		{
			j = 1;
			while (base[j])
			{
				if (base[j] == base[i] && i != j)
					return (0);
				j++;
			}
		}
		i++;
	}
	return (1);
}
int	value(char nb, char *base)
{
	int	i ;

	i = 0;

void	ft_atoi_base(char *str, char *base)
{
	int	i ;
	int	nb ;
	int	r ;
	int	lenght ;
	
	lenght = ft_strlen(base);
	if (!(error))
		return ;
	i = 0;
	nb = 1;
	r = 0;
	while ((str[i] => 9 && str[i] <= 13) || (str[i] = ' '))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] = '-')
			nb *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * lenght + (str[i] - 48);
		i++;
	}
	return (r * nb);
}
