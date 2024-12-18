/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:52:32 by thgaugai          #+#    #+#             */
/*   Updated: 2024/07/27 16:01:05 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i ;
	int	len ;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			len++;
		i++;
	}
	return (len);
}

char	*ft_clean(char *str)
{
	int		len ;
	char	*result ;
	int		i ;
	int		j ;

	len = ft_strlen(str);
	result = malloc(sizeof(char) * len + 1);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result[j] = str[i];
			j++;
		}
		i++;
	}
	result[j] = '\0';
	return (result);
}
