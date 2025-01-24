/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:09:45 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/24 17:37:57 by thgaugai         ###   ########.fr       */
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
		if (i == 0)
			ph[i].fork_right = &data->fork[data->nb_philo - 1];
		else
			ph[i].fork_right = &data->fork[i - 1];
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
		return (NULL);
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data->meal_required = ft_atoi(av[5]);
	else
		data->meal_required = 0;
	data->time_to_start = 0;
	data->someone_died = 0;
	data->mutex_death = malloc(sizeof(pthread_mutex_t));
	if (!data->mutex_death)
		return (NULL);
	if (pthread_mutex_init(data->mutex_death, NULL) != 0)
		return (NULL);
	data->mutex_print = malloc(sizeof(pthread_mutex_t));
	if (!data->mutex_print)
		return (NULL);
	if (pthread_mutex_init(data->mutex_print, NULL) != 0)
		return (NULL);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->fork)
		return (NULL);
	i = -1;
	while (++i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->fork[i], NULL) != 0)
			return (NULL);
	}
	return (data);
}

void	thread_init(t_data *data, t_philo *ph)
{
	int	i;

	i = 0;
	data->time_to_start = get_time();
	printf("start time : %ldms\n", get_time());
	while (i < data->nb_philo)
	{
		//ph[i].start_time = data->time_to_start;
		if (pthread_create(&ph[i].tid, NULL, routine, &ph[i]) != 0)
			return ;
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philo;

	//if (ac != 6)
	//	return (1);
	(void)ac;
	data = var_init(av);
	if (!data)
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
	thread_init(data, philo);
	check(philo, data);
	end_thread(philo, data);
	return (0);
}
