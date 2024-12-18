/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:04:16 by thgaugai          #+#    #+#             */
/*   Updated: 2024/07/28 18:21:35 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
int	ft_line_count(char *str)
{
	int	i ;
	int	res ;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == 10 || str[i] == ':')
			res++;
		i++;
	}
	return (res);
}

char	**ft_split_init(char *str)
{
	char	**result ;
	int	i ;
	int	j;

	i = 0;
	j = -1;
	result = malloc(sizeof(char *) * (ft_line_count(str)));
	if (result == NULL)
		return (0);
	while (ft_line_count(str) > i)
	{
		result[i] = malloc(sizeof(char) * 50);
		if (result[i] == NULL)
			return (0);
		else
			while (++j < 50)
				result[i][j] = '\0';
		i++;
	}
	return (result);
}

char	**ft_split(char *str)
{
	int	i ;
	int	j ;
	int	c ;
	char	**result ;

	result = ft_split_init(str);
	i = 0;
	j = 0 ;
	c = 0;
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == ':')
		{
			j++;
			c = 0;
		}
		else 
		{
			result[j][c] = str[i];
			c++;
		}
		i++;
	}
	return (result);
}
#include <unistd.h>
int	main()
{	
	char	**result;
	int	i ;
	int	j ;

	result = ft_split("2 : deux\n 4 : quatre\n");
	i = 0; 
	while (result[i])
	{
		j = 0;
		while (result[i][j])
		{
			write(1, &result[i][j], 1);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

			





