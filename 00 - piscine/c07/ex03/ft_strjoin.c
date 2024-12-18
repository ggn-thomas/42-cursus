/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:44:02 by thgaugai          #+#    #+#             */
/*   Updated: 2024/07/29 15:06:09 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i ;
	int	j ;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	len_total(int size, char **strs)
{
	int	j ;
	int	i ;
	int	total_len ;

	i = 0;
	j = 0;
	total_len = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			total_len += 1;
			j++;
		}
		i++;
	}
	total_len += size - 1;
	return (total_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i ;
	int		len ;
	char	*str ;

	if (size == 0)
		return (NULL);
	i = 0;
	len = len_total(size, strs);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (++i < len - 1)
		str[i] = '\0';
	i = 0;
	while (i < size)
	{
		str = ft_strcat(str, strs[i]);
		if (i < size - 1)
			ft_strcat(str, sep);
		i++;
	}
	return (str);
}
