/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:59:17 by thomas            #+#    #+#             */
/*   Updated: 2025/01/15 11:28:30 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;

}



void	is_eating(t_philo *philo)
{
	philo->is_eating = true;
	pthread_mutex_lock(philo->fork_letf);
	pthread_mutex_lock(philo->fork_right);
	usleep(philo->dt.time_to_eat);
	philo->is_eating = false;
	pthread_mutex_unlock(philo->fork_letf);
	pthread_mutex_unlock(philo->fork_right);
	routine_sleep(philo);
}





void	sleep_think(t_philo *philo)
{
	usleep(philo->dt->time_to_sleep);
}