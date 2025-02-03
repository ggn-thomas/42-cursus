/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:05:16 by thgaugai          #+#    #+#             */
/*   Updated: 2025/02/03 15:06:00 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philo;

	data = NULL;
	philo = NULL;
	if (ac < 5 || ac > 6)
		return (error("The number of arguments is incorrect !", data, philo,
				0));
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
	return (0);
}
