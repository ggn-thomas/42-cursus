/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:18:43 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/13 14:52:49 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*rrange(int start, int end)
{
	int len;
	int	*result;
	int	i;
	int	tmp;

	i = 0;
	len = 0;
	tmp = start;
	while (tmp != end)
	{
		len++;
		tmp--;
	}
	len+=1;
	result = malloc(sizeof(int)*len);
	if (!result)
		return (NULL);
	while (start >= end)
	{
		result[i] = start;
		printf("%d,", result[i]);
		i++;
		start--;
	}
	return (result);
}

int	*ft_rrange(int start, int end)
{
	int	len = 0;
	int	*result;
	int	i;
	int	tmp;

	if (end < 0)
		result = rrange(start, end);
	else
	{
		tmp = start;
		while (tmp != end)
		{
			len++;
			tmp++;
		}
		result = malloc(sizeof(int) * len);
		if (!result)
			return (NULL);
		i = 0;
		while (start <= end)
		{
			result[i] = end;
			printf("%d,", result[i]);
			i++;
			end--;
		}
	}
	return (result);
}

int	main(void)
{
	ft_rrange(0, -3);
	return (0);
}