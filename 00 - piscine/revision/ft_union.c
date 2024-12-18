/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_union.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 08:52:06 by thgaugai          #+#    #+#             */
/*   Updated: 2024/08/01 09:20:36 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

void	ft_union(char *s1, char *s2)
{
	char	*str;
	int	i ;
	int	j ;
	int	compt ;

	str = ft_strcat(s1, s2);
	i = 0;
	j = 0;
	compt = 0;
	while (str[i])
	{
		if (i == 0)
		{
			write(1, &str[i], 1);
		}
		else
		{
			j = i - 1;
			compt = 0;
			while (j != 0)
			{
				if (str[j] == str[i])
					compt++;
				j--;
			}
			if (compt == 0)
				write(1, &str[i], 1);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*s1 = argv[1];
	char	*s2 = argv[2];
	
	(void)argc;
	ft_union(s1, s2);
}	
