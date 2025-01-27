/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:27:22 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/27 11:59:00 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	someone_died(t_philo *philo)
{
    philo->dt->someone_died = 1;
    print_action(philo, DEAD);
	return (1);
}

int check_meal(t_philo *philo)
{
    if (philo->nb_meal >= philo->dt->meal_required && philo->dt->meal_required > 0)
        return (1);
    return (0);
}

int check_death(t_philo *philo)
{
	long int	current_time;

	pthread_mutex_lock(philo->dt->mutex_death);
	current_time = get_time() - philo->last_meal;
	if (current_time >= philo->dt->time_to_die)
	{
		pthread_mutex_unlock(philo->dt->mutex_death);
		return (someone_died(philo));
	}
	pthread_mutex_unlock(philo->dt->mutex_death);
	return (0);
}

void	check(t_philo *philo, t_data *dt)
{
	int	i;
	//int	all_ate;

	while(!dt->someone_died)
	{
		i = -1;
		while (++i < philo->dt->nb_philo)
		{
			if (check_death(&philo[i]) || check_meal(&philo[i]))
				dt->someone_died = 1;
		}
	}
}

