/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:59:17 by thomas            #+#    #+#             */
/*   Updated: 2025/02/03 11:41:44 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_action(t_philo *philo, char *action)
{
	pthread_mutex_lock(philo->dt->mutex_death);
	if (!philo->dt->someone_died || action[0] == 'd')
	{
		printf("%ld %d %s\n", get_time() - philo->thread_start, philo->id,
			action);
	}
	pthread_mutex_unlock(philo->dt->mutex_death);
}

static void	is_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	print_action(philo, FORK);
	pthread_mutex_lock(philo->fork_right);
	print_action(philo, FORK);
	print_action(philo, EAT);
	philo->last_meal = get_time();
	ft_usleep(philo->dt->time_to_eat);
	philo->nb_meal++;
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_unlock(philo->fork_left);
}

static void	is_sleeping_thinking(t_philo *philo)
{
	print_action(philo, SLEEP);
	ft_usleep(philo->dt->time_to_sleep);
	print_action(philo, THINK);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->dt->nb_philo == 1)
	{
		printf("%d %d %s\n", 0, philo->id, "has taken a fork");
		return (NULL);
	}
	if (philo->id % 2 != 0)
		ft_usleep(philo->dt->time_to_eat * 0.9 + 1);
	else
		ft_usleep(10);
	while (!philo->dt->someone_died)
	{
		is_eating(philo);
		is_sleeping_thinking(philo);
	}
	return (NULL);
}
