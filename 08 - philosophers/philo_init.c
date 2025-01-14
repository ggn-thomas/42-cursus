/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:09:45 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/14 18:15:41 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	var_init(char **av)
{
	t_data	data;
	int	i;

	i = -1;
	data.nb_philo = ft_atoi(av[1]);
	data.time_to_die = ft_atoi(av[2]);
	data.time_to_eat = ft_atoi(av[3]);
	data.time_to_sleep = ft_atoi(av[4]);
	data.fork = malloc(sizeof(pthread_mutex_t) * data.nb_philo);
	if (!data.fork)
		return ;
	i = -1;
	while (++i < data.nb_philo)
	{
		pthread_mutex_init(data.fork[i]); //je protège les fourchettes.
	}

}

void	thread_init(t_data *data, t_philo *ph)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
	{
		pthread_create(ph[i]->tid, NULL, routine, ph[i]);
	}
}

void	philo_init(t_data *data)
{
	int	i;
	t_philo	*ph;
	
	ph = malloc(sizeof(t_philo) * data.nb_philo);
	if (!ph)
		return ;
	i = -1;
	while (++1 < data->nb_philo)
	{
		ph[i]->id = i + 1;
		ph[i]->dt = data;
		ph[i]->fork_letf = data->fork[i];
		ph[i]->fork_right = 
	}
}

int	main(int ac, char **av)
{
	if (ac != 5)
		return (1);
	var_init(av);
}
