/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:27:22 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/23 17:05:08 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	someone_died(t_data *data)
{
	int	status;

	pthread_mutex_lock(data->mutex_death);
	status = data->someone_died;
	pthread_mutex_unlock(data->mutex_death);
	return (status);
}


int check_death(t_philo *philo)
{
	int	current_time;

	pthread_mutex_lock(philo->dt->mutex_death);
	current_time = get_time() - philo->last_meal;
	if (current_time >= philo->dt->time_to_die)
	{
		philo->dead = 1;
		print_action(philo, DEAD);
		pthread_mutex_unlock(philo->dt->mutex_death);
		return (1);
	}
	pthread_mutex_unlock(philo->dt->mutex_death);
	return (0);
}


void	check(t_philo *philo, t_data *dt)
{
	int	i;

	while(1)
	{
		i = -1;
		while (++i < philo->dt->nb_philo)
		{
			if (check_death(&philo[i]))
			{
				dt->someone_died = 1;
				return ;
			}
			usleep(100);
		}
	}
}