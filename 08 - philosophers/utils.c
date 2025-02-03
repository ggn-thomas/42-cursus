/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:21:03 by thgaugai          #+#    #+#             */
/*   Updated: 2025/02/03 11:30:47 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	error(char *str, t_data *dt, t_philo *ph, int malloc)
{
	if (malloc)
	{
		if (ph)
			free(ph);
		if (dt->mutex_death)
			free(dt->mutex_death);
		if (dt->mutex_print)
			free(dt->mutex_print);
		if (dt)
			free(dt);
	}
	printf("%s\n", str);
	return (1);
}

long int	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	end_thread(t_philo *philo, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
		pthread_mutex_destroy(&data->fork[i]);
	i = -1;
	while (++i < data->nb_philo)
		pthread_join(philo[i].tid, NULL);
	pthread_mutex_destroy(data->mutex_death);
	pthread_mutex_destroy(data->mutex_print);
	free(data->fork);
	free(data->mutex_death);
	free(data->mutex_print);
	free(data);
	free(philo);
}

int	ft_usleep(long int ms)
{
	long int	current_time;

	current_time = get_time();
	while ((get_time() - current_time) < ms)
		usleep(150);
	return (1);
}

long	ft_atoi(char *nptr)
{
	int		i;
	long	r;
	char	*str;

	str = (char *)nptr;
	i = 0;
	r = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - 48);
		i++;
	}
	return (r);
}
