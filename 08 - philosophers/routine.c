/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:59:17 by thomas            #+#    #+#             */
/*   Updated: 2025/01/16 16:38:29 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->is_eating == false)
	{
		philo->is_eating = true;
		ft_usleep(philo->dt.time_to_eat * 0.9 + 1);
	}
	while (1)
	{
		if (philo->dt.time_to_die <= get_time() - philo->last_meal)
			return ;
		is_eating(philo);
		is_spleeping_thinking(philo);
	}
}

void	is_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_letf);
	printf("%ldms %d has taken a fork\n", get_time() - philo->start_time, philo->id);
	pthread_mutex_lock(philo->fork_right);
	printf("%ldms %d has taken a fork\n", get_time() - philo->start_time, philo->id);
	ft_usleep(philo->dt.time_to_eat);
	printf("%ldms %d is eating\n", get_time() - philo->start_time, philo->id);
	philo->last_meal = get_time();
	philo->nb_meal++;
	pthread_mutex_unlock(philo->fork_letf);
	pthread_mutex_unlock(philo->fork_right);
}

void	is_sleeping_thinking(t_philo *philo)
{
	ft_usleep(philo->dt.time_to_sleep);
	printf("%ldms %d is spleeping\n", get_time() - philo->start_time, philo->id);
	printf("%ldms %d is thinking\n", get_time() - philo->start_time, philo->id);
}
