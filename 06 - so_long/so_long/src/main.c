/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:01:31 by thomas            #+#    #+#             */
/*   Updated: 2024/12/18 10:55:23 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"

int	main(int ac, char **av)
{
	char	**map;

	if (ac != 2)
	{
		write(1, "Error\nThe number of argument is incorrect !\n", 44);
		return (0);
	}
	if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
	{
		ft_printf("Error\nInvalide file type !\n");
		return (0);
	}
	map = map_init(av[1]);
	window_init(map);
	return (0);
}
