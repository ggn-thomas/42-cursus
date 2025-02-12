/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:09:45 by thgaugai          #+#    #+#             */
/*   Updated: 2025/02/12 16:31:51 by thomas           ###   ########.fr       */
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

static int	finish_var_init(t_data *data, char **av)
{
	if (av[5])
	{
		if (ft_atol(av[5]) == 0)
		{
			free(data);
			printf("The number of meals is not consistent !\n");
			return (0);
		}
		data->meal_required = ft_atol(av[5]);
	}
	else
		data->meal_required = 0;
	return (1);
}

t_data	*var_init(char **av)
{
	t_data	*data;
	
	data = malloc(sizeof(t_data));
	if (!data)
	{
		printf("Error initializing variables !\n");
		return (NULL);
	}
	data->nb_philo = ft_atol(av[1]);
	data->time_to_die = ft_atol(av[2]);
	data->time_to_eat = ft_atol(av[3]);
	data->time_to_sleep = ft_atol(av[4]);
	data->start = 0;
	data->someone_died = 0;
	data->ready = 0;
	if (!finish_var_init(data, av))
		return (NULL);
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
			return (error("Error initializing thread !\n", data, ph, 1));
		i++;
	}
	i = -1;
	data->start = get_time();
	while (++i < data->nb_philo)
	{
		ph[i].thread_start = data->start;
		ph[i].last_meal = data->start;
	}
	data->ready = 1;
	return (1);
}
