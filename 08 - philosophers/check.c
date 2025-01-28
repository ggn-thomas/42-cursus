/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:27:22 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/28 17:05:45 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_parsing(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!(str[i][j] >= '0' && str[i][j] <= '9'))
			{
				printf("Invalide syntax !\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	someone_died(t_philo *philo)
{
	print_action(philo, DEAD);
	return (1);
}

int	check_meal(t_philo *philo)
{
	if (philo->nb_meal >= philo->dt->meal_required
		&& philo->dt->meal_required > 0)
		return (1);
	return (0);
}

int	check_death(t_philo *philo)
{
	long int	current_time;

	pthread_mutex_lock(philo->dt->mutex_death);
	current_time = get_time() - philo->last_meal;
	if (current_time >= philo->dt->time_to_die)
	{
		philo->dt->someone_died = 1;
		pthread_mutex_unlock(philo->dt->mutex_death);
		someone_died(philo);
		return (1);
	}
	pthread_mutex_unlock(philo->dt->mutex_death);
	return (0);
}

void	check(t_philo *philo, t_data *dt)
{
	int	i;
	int	all_ate_enough;

	while (!dt->someone_died)
	{
		i = -1;
		all_ate_enough = 1;
		while (++i < philo->dt->nb_philo)
		{
			if (check_death(&philo[i]))
			{
				dt->someone_died = 1;
				break ;
			}
			if (dt->meal_required > 0 && philo[i].nb_meal < dt->meal_required)
				all_ate_enough = 0;
		}
		if (dt->meal_required > 0 && all_ate_enough && dt->nb_philo != 1)
		{
			printf("All philos have eaten enough times !\n");
			dt->someone_died = 1;
			break ;
		}
		usleep(1000);
	}
}
