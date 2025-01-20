/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:21:03 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/20 15:51:38 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
}

void	end_thread(t_philo *philo, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
		pthread_mutex_destroy(&data->fork[i]);
	pthread_mutex_destroy(data->mutex_death);
	free(data->fork);
	free(data->mutex_death);
	free(philo);
}

void	ft_usleep(int time)
{
	time *= 1000;
	usleep(time);
}