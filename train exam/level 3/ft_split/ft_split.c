/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:35:39 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/29 09:00:18 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
int	count_letter(char *str)
{
	int	i = 0 ;

	while (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i])
		i++;
	return (i);
}

int	count_word(char *str)
{
	int	count;
	int	i;
	int	len;

	i = 0;
	count = 0;
	len = ft_strlen(str) - 1;
	while(str[i])
	{
		if (i == 0 && str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
			count++;
		if ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && (i != len))
			count++;
		i++;
	}
	return (count);
}

char	*ft_strlcpy(char *dest, char *src, int stop)
{
	int	i;

	i = 0;
	while (src[i] && i < stop)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_fill(char **tab, int len, int i, char *str)
{
	tab[i] = malloc(sizeof(char) * len + 1);
	if (!tab[i])
	{
		while (i)
		{
			free(tab[i]);
			i--;
		}
		free(tab);
		return (NULL);
	}
	tab[i] = ft_strlcpy(tab[i], str, len);
	return (tab[i]);
}

char	**ft_split(char *str)
{
	char **tab;
	int	i;
	int	len;

	i = 0;
	len = 0;
	tab = malloc(sizeof(char *) * count_word(str) + 1);
	if (!tab)
		return (NULL);
	while (*str)
	{
		if(*str != ' ' && *str != '\n' && *str != '\t')
		{
			len = count_letter(str);
			if (!ft_fill(tab, len, i++, str))
				return (NULL);
			str+=len;
		}
		else
			str++;
	}
	tab[i] = NULL;
	return (tab);
}

int	main(int ac, char **av)
{
	char	**result;

	(void)ac;
	result = ft_split(av[1]);
	int	i = 0;
	while (result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
	return (0);
}