/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:27:22 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/24 17:13:03 by thgaugai         ###   ########.fr       */
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
	long int	current_time;

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
	int	all_ate;

	while(!dt->someone_died)
	{
		i = -1;
		all_ate = 1;
		while (++i < philo->dt->nb_philo)
		{
			if (check_death(&philo[i]))
			{
				dt->someone_died = 1;
				return ;
			}
			if (philo[i].nb_meal < dt->meal_required && dt->meal_required > 0)
				all_ate = 0;
		}
		if (dt->meal_required > 0 && all_ate)
		{
			printf("All the philosophers have finished eating !\n");
			dt->someone_died = 1;
			return ;
		}
		usleep(1000);
	}
}
