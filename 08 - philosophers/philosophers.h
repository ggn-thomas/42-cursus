/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:14:45 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/14 18:09:07 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>// ! à retirer !

typedef struct	s_data
{
	int	time_to_die;
	int	time_to_eat;
	int	time_to_think;
	int	time_to_sleep;
	int	nb_philo;
	pthread_mutex_t	fork;
}	t_data;

typedef struct	s_philo
{
	pthread_mutex_t	fork_letf;
	pthread_mutex_t	fork_right;
	int	id;
	t_data	dt;
	pthread	tid;
}	t_philo;


//utils
int	ft_atoi(char *nptr);

#endif
