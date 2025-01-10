/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:53:14 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/10 11:48:26 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strlcpy(char *dest, char *src, int limit)
{
	int	i;

	i = 0;
	while (src[i] && limit - 1)
	{
		dest[i] = src[i];
		i++;
		limit--;
	}
	return (dest);
}

int	count_word(char *str)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (str[i])
	{
		if (i == 0)
			counter++;
		if (str[i] == '\t' || str[i] == '\n' || str[i] == ' ')
			counter++;
		i++;
	}
	return(counter);
}

int	ft_count_letter(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\t' && str[i] != '\n' && str[i] != ' ')
		i++;
	return (i);
}

char	**ft_fill(char **tab, int i, int len, char *str)
{
	tab[i] = malloc(sizeof(char) * (len + 1));
	if (!tab[i])
	{
		while (i > 0)
		{
			free(tab[i - 1]);
			i--;
		}
		free(tab);
		return (NULL);
	}
	tab[i] = ft_strlcpy(tab[i], str, len + 1);
	tab[i][len] = '\0';
	return (tab);
}

char	**ft_split(char *str)
{
	char	**tab;
	int	len;
	int	i;

	i = 0;
	len = 0;
	tab = malloc(sizeof(char *) * count_word(str) + 1);
	if (!tab)
		return (NULL);
	while (*str)
	{
		if (*str != '\t' && *str != '\n' && *str != ' ')
		{
			len = ft_count_letter(str);
			if (!(ft_fill(tab, i++, len, str)))
				return (NULL);
			str += len;
		}
		else
			str++;
	}
	tab[i] = NULL;
	return (tab);
}

#include <stdio.h>

int	main(void)
{
	int	i=0;
	char	**result;
	char	*s = "   Hello,   Flavio\t Wuensche!  ";
	result = ft_split(s);
	while (result[i])
		printf("%s\n", result[i++]);
}