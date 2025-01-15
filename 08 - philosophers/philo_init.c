/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:09:45 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/15 11:16:08 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_init(t_data *data)
{
	int	i;
	t_philo	*ph;

	ph = malloc(sizeof(t_philo) * data->nb_philo);
	if (!ph)
		return ;
	i = -1;
	while (++i < data->nb_philo)
	{
		ph[i].id = i + 1;
		ph[i].dt = *data;
		ph[i].fork_letf = &data->fork[i + 1];
		ph[i].is_eating = false;
		if (i == 0)
		{
			ph[i].fork_right = &data->fork[data->nb_philo];
			printf("id : %d | fork left : %d | fork right : %d\n", ph[i].id, i + 1 , data->nb_philo);
		}
		else
		{
			ph[i].fork_right = &data->fork[i];
			printf("id : %d | fork left : %d | fork right : %d\n", ph[i].id, i + 1 , i);
		}
	}
}

void	var_init(char **av)
{
	t_data	data;
	int	i;

	i = -1;
	data.nb_philo = ft_atoi(av[1]);
	data.time_to_die = ft_atoi(av[2]);
	data.time_to_eat = ft_atoi(av[3]);
	data.time_to_sleep = ft_atoi(av[4]);
	data.fork = malloc(sizeof(pthread_mutex_t) * data.nb_philo);
	if (!data.fork)
		return ;
	i = -1;
	while (++i < data.nb_philo)
	{
		if (pthread_mutex_init(&data.fork[i], NULL) != 0)
			return ;
	}
	philo_init(&data);
}

void	thread_init(t_data *data, t_philo *ph)
{
	int	i;
	int	stop;

	stop = data->nb_philo;
	if (data->nb_philo % 2 != 0)
		stop -= 1;
	else
		stop = data->nb_philo;
	i = 0;
	while (i < stop)
	{
		if (i % 2 != 0)
		{
			if (pthread_create(ph[i]->tid, NULL, routine, ph[i]) != 0)
				return ;
		}
		else
			routine_sleep(ph[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 5)
		return (1);
	var_init(av);
	return (0);
}
