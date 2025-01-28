/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:09:45 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/28 16:24:38 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*philo_init(t_data *data)
{
	int		i;
	t_philo	*ph;

	ph = malloc(sizeof(t_philo) * data->nb_philo);
	if (!ph)
		return (NULL);
	i = -1;
	while (++i < data->nb_philo)
	{
		ph[i].id = i + 1;
		ph[i].dt = data;
		ph[i].fork_left = &data->fork[i];
		ph[i].last_meal = 0;
		ph[i].nb_meal = 0;
		ph[i].dead = 0;
		ph[i].thread_start = 0;
	}
	return (ph);
}

t_data	*var_init(char **av)
{
	t_data	*data;
	int		i;

	i = -1;
	data = malloc(sizeof(t_data));
	if (!data)
	{
		printf("Error initializing variables !\n");
		return (NULL);
	}
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->start = 0;
	data->someone_died = 0;
	if (av[5])
		data->meal_required = ft_atoi(av[5]);
	else
		data->meal_required = 0;
	return (data);
}

int	mutex_init(t_data *data)
{
	int	i;

	data->mutex_death = malloc(sizeof(pthread_mutex_t));
	if (!data->mutex_death)
		return (0);
	if (pthread_mutex_init(data->mutex_death, NULL) != 0)
		return (0);
	data->mutex_print = malloc(sizeof(pthread_mutex_t));
	if (!data->mutex_print)
		return (0);
	if (pthread_mutex_init(data->mutex_print, NULL) != 0)
		return (0);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->fork)
		return (0);
	i = -1;
	while (++i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->fork[i], NULL) != 0)
			return (0);
	}
	return (1);
}

int	thread_init(t_data *data, t_philo *ph)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		ph[i].fork_right = ph[(i + 1) % data->nb_philo].fork_left;
		if (pthread_create(&ph[i].tid, NULL, routine, &ph[i]) != 0)
		{
			printf("Error initializing thread !\n");
			return (0);
		}
		i++;
	}
	i = -1;
	data->start = get_time();
	while (++i < data->nb_philo)
	{
		ph[i].thread_start = data->start;
		ph[i].last_meal = data->start;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philo;

	if (ac < 5 || ac > 7 || !check_parsing(av))
		return (1);
	data = var_init(av);
	if (!data)
		return (1);
	if (!mutex_init(data))
	{
		printf("Error initializing mutex !\n");
		return (1);
	}
	philo = philo_init(data);
	if (!philo)
	{
		printf("Error initializing variable !\n");
		return (1);
	}
	if (!thread_init(data, philo))
		return (1);
	check(philo, data);
	end_thread(philo, data);
	return (0);
}
