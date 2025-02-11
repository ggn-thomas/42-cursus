/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:46:53 by thgaugai          #+#    #+#             */
/*   Updated: 2025/02/11 15:28:44 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (0);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
        int             i;
        int             j;
        int             len;
        char    *dest;

        i = 0;
        j = 0;
        len = ft_strlen(s1) + ft_strlen(s2);
        dest = malloc(sizeof(char) * len + 1);
        if (!dest)
                return (NULL);
        while (s1[i])
        {
                dest[i] = s1[i];
                i++;
        }
        while (s2[j])
        {
                dest[i + j] = s2[j];
                j++;
        }
        dest[i + j] = '\0';
        return (dest);
}
