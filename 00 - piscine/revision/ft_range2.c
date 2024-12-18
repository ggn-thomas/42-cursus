/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:51:19 by thgaugai          #+#    #+#             */
/*   Updated: 2024/08/01 16:09:33 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int	*ft_range(int start, int end)
{
	int	i ;
//	int	j ;
	int	temp ;
	int	*result;

	i = 0;
	
	
		temp = start;
		while (start != 0)
		{
			start++;
			i++;
		}
		result = malloc(sizeof(int) * (i + end));
		i = 0;
		while (temp != 0)
		{
			result[i] = temp;
			temp++;
			i++;
		}
		while(temp >= end)
		{
			result[i] = temp;
			temp++;
		}
		i = 0;
		while (result[i])
		{
			write(1, &result[i], 1);
			i++;
		}
		return (result);
	
	
}

/*
	else if (end < 0)
	{
		i = 0;
		while (end != 0)
		{
			end++;
			i++;
		}
	}
	else if (end < 0 && start < 0)
	{
		i = 0;
		j = 0;
		while (end 
*/

int	main()
{
	ft_range(-5, 20);
}
