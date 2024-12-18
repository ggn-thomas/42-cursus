/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:11:52 by thgaugai          #+#    #+#             */
/*   Updated: 2024/07/16 17:29:39 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i ;
	unsigned int	j ;

	i = 0;
	j = 0;
	while (src[j])
	{
		if (size && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		j++;
	}
	dest[i] = '\0';
	return (j);
}
