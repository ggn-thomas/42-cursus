/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:59:17 by thomas            #+#    #+#             */
/*   Updated: 2025/01/20 16:25:41 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	is_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	printf("%d %d has taken a fork\n", get_time() - philo->start_time, philo->id);
	pthread_mutex_lock(philo->fork_right);
	printf("%d %d has taken a fork\n", get_time() - philo->start_time, philo->id);
	ft_usleep(philo->dt.time_to_eat);
	printf("%d %d is eating\n", get_time() - philo->start_time, philo->id);
	philo->last_meal = get_time();
	philo->nb_meal++;
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
}

void	is_sleeping_thinking(t_philo *philo)
{
	printf("%ld %d is sleeping\n", get_time() - philo->start_time, philo->id);
	ft_usleep(philo->dt.time_to_sleep);
	printf("%ld %d is thinking\n", get_time() - philo->start_time, philo->id);
}

int check_death(t_philo *philo)
{
	pthread_mutex_lock(philo->dt.mutex_death);
	if (philo->dt.someone_died == 1)
	{
		pthread_mutex_unlock(philo->dt.mutex_death);
		return (1);
	}
	if (philo->dt.time_to_die <= get_time() - philo->last_meal)
	{
		philo->dt.someone_died = 1;
		pthread_mutex_unlock(philo->dt.mutex_death);
		return (1);
	}
	pthread_mutex_unlock(philo->dt.mutex_death);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(philo->dt.time_to_eat * 0.9 + 1);
	while (!check_death(philo))
	{
		is_eating(philo);
		is_sleeping_thinking(philo);
	}
	return (NULL);
}
