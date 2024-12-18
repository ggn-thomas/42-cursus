/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 08:29:45 by thgaugai          #+#    #+#             */
/*   Updated: 2024/10/15 14:51:42 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strlen(char *str)
{
	int	i ;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_count_words(char *str)
{
	int	i ;
	int	len ;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (i == 0 && str[i] != ' ' )
			len++;
		else if ((str[i] == ' ') && (str[i + 1] != ' ') && (i != ft_strlen(str) - 1))
			len++;
		i++;
	}
	return (len);
}
#include <stdio.h>
int	main()
{
	char	*str = "salut ca va";

	printf("%d",ft_count_words(str));
}

