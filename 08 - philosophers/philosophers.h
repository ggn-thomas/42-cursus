/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:14:45 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/15 11:15:43 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdbool.h>
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
	pthread_mutex_t	*fork;
}	t_data;

typedef struct	s_philo
{
	pthread_mutex_t	*fork_letf;
	pthread_mutex_t	*fork_right;
	int	id;
	t_data	dt;
	pthread_t	tid;
	bool	is_eating;
}	t_philo;


//utils
int	ft_atoi(char *nptr);
void	routine(void *arg);

#endif
