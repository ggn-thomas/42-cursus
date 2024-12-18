/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builders.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:04:13 by thgaugai          #+#    #+#             */
/*   Updated: 2024/07/31 16:35:14 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	count_line(char *buffer)
{
	int	line;
	int	i;

	i = 0;
	line = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			line++;
		i++;
	}
	return (line);
}

char	**create_tab(char *buffer)
{
	char	**tab ;
	int		i ;

	i = 0;
	tab = malloc(sizeof(char *) * (count_line(buffer)));
	if (tab == NULL)
		return (0);
	while (count_line(buffer) > i)
	{
		tab[i] = malloc(sizeof(char) * count_line(buffer));
		if (tab[i] == NULL)
			return (0);
		i++;
	}
	return (tab);
}

char	**fill_tab(char **tab, char *buffer)
{
	int	i ;
	int	j ;
	int	k ;
	int	len ;

	len = count_line(buffer);
	i = 0;
	k = 0;
	j = 0;
	while (i < len)
	{
		j = 0;
		while (tab[i][j] != '\n' && buffer[k] != '\0')
		{
			tab[i][j] = buffer[k];
			write(1, &tab[i][j], 1);
			j++;
			k++;
		}
		i++;
	}
	return (tab);
}

void	search_number(char *buffer)
{
	char	**tab;
	int		length;

	length = count_line(buffer);
	tab = create_tab(buffer);
	tab = fill_tab(tab, buffer);
}
