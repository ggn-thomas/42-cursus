/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:27:22 by thgaugai          #+#    #+#             */
/*   Updated: 2025/02/10 18:22:52 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_avlen(char *str)
{
	int	i;
	int	count;

	count =0;
	i = 0;
	while (str[i] == '0')
		i++;
	while (str[i])
	{
		i++;
		count++;
	}
	return (count);
}

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
		if (ft_avlen(str[i]) > 12)
		{
			printf("The parameter is too large !\n");
			return (0);
		}
		if (ft_atol(str[i]) >= 2147483647)
		{
			printf("The parameter is too large !\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	someone_died(t_philo *philo)
{
	print_action(philo, DEAD);
	return (1);
}

static int	check_death(t_philo *philo)
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
			dt->someone_died = 1;
			break ;
		}
		usleep(100);
	}
}
