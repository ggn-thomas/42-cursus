/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:05:16 by thgaugai          #+#    #+#             */
/*   Updated: 2025/02/11 09:40:25 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_avlen(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] == '0')
		i++;
	while (str[i])
	{
		i++;
		count++;
	}
	return (count);
}

static int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	printf("Invalide syntax !\n");
	return (0);
}

int	check_parsing(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!(is_digit(str[i][j])))
				return (0);
			j++;
		}
		if (ft_avlen(str[i]) > 12)
			return (error("The parameter is too large !", NULL, NULL, 0));
		if (ft_atol(str[i]) >= 2147483647)
			return (error("The parameter is too large !", NULL, NULL, 0));
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philo;

	data = NULL;
	philo = NULL;
	if (ac < 5 || ac > 6)
		return (error("The number of arguments is incorrect !", data, philo,
				0));
	if (ft_atol(av[1]) == 0)
		return (error("There are no philosophers !", data, philo, 0));
	if (!check_parsing(av))
		return (1);
	data = var_init(av);
	if (!data)
		return (1);
	if (!mutex_init(data))
		return (error("Error initializing mutex !\n", data, philo, 1));
	philo = philo_init(data);
	if (!philo)
		return (error("Error initializing philosophers !\n", data, philo, 1));
	if (!thread_init(data, philo))
		return ((error("Error initializing thread !\n", data, philo, 1)));
	check(philo, data);
	end_thread(philo, data);
	return (1);
}
