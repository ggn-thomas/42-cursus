/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 16:27:42 by thgaugai          #+#    #+#             */
/*   Updated: 2024/07/28 11:10:00 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i ;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_argv(char *argv)
{
	int	i ;
	int	len ;
	int	compt ;

	len = ft_strlen(argv);
	i = 0;
	compt = 0;
	while (i < len)
	{
		if (!(argv[i] >= '0' && argv[i] <= '9'))
		{
			compt++;
		}
		if (compt == len)
		{
			write(1, "The arguments are not compatible !\n", 36);
			write(1, "Please enter number.\n", 22);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_argc(int argc, char **argv)
{	
	if (argc > 3)
	{
		write(1, "There are too many arguments !\n", 31);
		return (0);
	}
	else if (argc == 1)
	{
		write(1, "Insufficient number of arguments !\n", 36);
		return (0);
	}
	else if (argc == 2)
	{
		if (!(check_argv(argv[1])))
			return (0);
	}
	else if (argc == 3)
	{
		if (!(check_argv(argv[2])))
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (!(check_argc(argc, argv)))
		return (0);
}
