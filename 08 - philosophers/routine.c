/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:59:17 by thomas            #+#    #+#             */
/*   Updated: 2025/01/24 17:37:36 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_action(t_philo *philo, char *action)
{
	long int	current_time;

	pthread_mutex_lock(philo->dt->mutex_print);
	if (!philo->dt->someone_died)
	{
		printf("%ldms | %ldms\n", get_time(), philo->dt->time_to_start);
		current_time = get_time() - philo->dt->time_to_start;
		printf("%ldms %d %s\n", current_time, philo->id, action);
	}
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
	print_action(philo, SLEEP);
	ft_usleep(philo->dt->time_to_sleep);
	print_action(philo, THINK);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_meal = get_time();
	if (philo->id % 2 != 0)
		ft_usleep(philo->dt->time_to_eat * 0.9 + 1);
	while (!someone_died(philo->dt))
	{
		is_eating(philo);
		is_sleeping_thinking(philo);
	}
	return (NULL);
}
