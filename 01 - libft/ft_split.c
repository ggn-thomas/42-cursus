/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:48:40 by thgaugai          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/27 00:48:31 by thomas           ###   ########.fr       */
=======
/*   Updated: 2024/10/17 14:02:02 by thomas           ###   ########.fr       */
>>>>>>> 7925e06 (initial commit 42)
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

static int	ft_count_letter(char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**ft_fill(char **dest, int i, int len, char const *s)
{
	dest[i] = malloc(sizeof(char) * (len + 1));
	if (!dest[i])
	{
		while (i > 0)
		{
			free(dest[i - 1]);
			i--;
		}
		free(dest);
		return (NULL);
	}
	ft_strlcpy(dest[i], s, len + 1);
	dest[i][len] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		i;
	int		len;

	len = 0;
	i = 0;
	dest = malloc(sizeof(char *) * (ft_count_word((char *)s, c) + 1));
	if (!dest)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = ft_count_letter((char *)s, c);
			if (!ft_fill(dest, i, len, s))
				return (NULL);
			s += len;
			i++;
		}
		else
			s++;
	}
	dest[i] = NULL;
	return (dest);
}
<<<<<<< HEAD
#include "libft.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	(void)argc;
    char **result;
    int i = 0;

    result = ft_split(argv[1], argv[2][0]);

    while (result[i])
    {
        printf("mot %d: %s\n", i + 1, result[i]);
        i++;
    }
    i = 0;
    while (result[i])
    {
        free(result[i]);
        i++;
    }
    free(result);

    return (0);
}



      
=======
>>>>>>> 7925e06 (initial commit 42)
