/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:59:17 by thomas            #+#    #+#             */
/*   Updated: 2025/01/28 11:12:49 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_action(t_philo *philo, char *action)
{

	pthread_mutex_lock(philo->dt->mutex_print);
	if (philo->dt->someone_died)
	{
		pthread_mutex_unlock(philo->dt->mutex_print);
		return ;
	}
	printf("%ldms %d %s\n", get_time() - philo->thread_start, philo->id, action);
	pthread_mutex_unlock(philo->dt->mutex_print);
}

void	is_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	print_action(philo, FORK);
	pthread_mutex_lock(philo->fork_right);
	print_action(philo, FORK);
	print_action(philo, EAT);
	philo->last_meal = get_time();
	ft_usleep(philo->dt->time_to_eat);
	philo->nb_meal++;
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
}

void	is_sleeping_thinking(t_philo *philo)
{
	ft_usleep(philo->dt->time_to_sleep);
	print_action(philo, SLEEP);
	print_action(philo, THINK);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
		ft_usleep(philo->dt->time_to_eat * 0.9 + 1);
	while (!philo->dt->someone_died)
	{
		is_eating(philo);
		is_sleeping_thinking(philo);
	}
	return (NULL);
}
