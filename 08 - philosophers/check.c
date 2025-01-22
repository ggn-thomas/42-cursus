/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:27:22 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/22 10:29:12 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int check_death(t_philo *philo)
{
	pthread_mutex_lock(philo->dt->mutex_death);
	if (get_time() - philo->last_meal >= philo->dt->time_to_die && philo->nb_meal > 0)
	{
		pthread_mutex_unlock(philo->dt->mutex_death);
		return (1);
	}
	pthread_mutex_unlock(philo->dt->mutex_death);
	return (0);
}

void	check(t_philo *philo)
{
	int	i;

	while(1)
	{
		i = -1;
		while (++i < philo->dt->nb_philo)
		{
			if (check_death(&philo[i]))
			{
				philo[i].dt->someone_died = 1;
				print_action(&philo[i], DEAD);
				return ;
			}
		usleep(100);
		}
	}
}