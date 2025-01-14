/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosphers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:09:45 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/14 09:09:55 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	var_init(char **av)
{
	t_data	data;
	t_philo	*ph;
	int	i;

	i = -1;
	data.nb_philo = ft_atoi(av[1]);
	data.time_to_die = ft_atoi(av[2]);
	data.time_to_eat = ft_atoi(av[3]);
	data.time_to_sleep = ft_atoi(av[4]);
	ph = malloc(sizeof(t_philo) * data.nb_philo);
	if (!ph)
		return ;

}
void	thread_init(t_data *data, t_philo )
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
	{
		pthread_create()
	}
}
void	philo_init(t_philo *ph, t_data *data)
{
	int	i;

	i = -1;
	while (++1 < data->nb_philo)
	{
		ph[i]->id = i + 1;
		ph[i]->dt = data;
	}
}

int	main(int ac, char **av)
{
	if (ac != 5)
		return (1);
	var_init(av);
}
