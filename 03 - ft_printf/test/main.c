/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:56:15 by thgaugai          #+#    #+#             */
/*   Updated: 2024/11/15 16:03:20 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	dec = -42;
	char	c = 'c';
	char	*str = "hello 42";
	unsigned int	unsignednumber = -1;

	printf("%d\n", ft_printf("%s", str));
	printf("%d\n", printf("%s", str));
}
