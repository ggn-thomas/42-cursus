/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:14:45 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/20 11:39:04 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdbool.h>
# include <sys/time.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_data
{
	int	time_to_die;
	int	time_to_eat;
	int	time_to_think;
	int	time_to_sleep;
	int	time_to_start;
	int	nb_philo;
	int	someone_died;
	pthread_mutex_t	*mutex_death;
	pthread_mutex_t	*fork;
}	t_data;

typedef struct	s_philo
{
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	int	id;
	int	last_meal;
	int	nb_meal;
	int	start_time;
	t_data	dt;
	pthread_t	tid;
}	t_philo;


int	ft_atoi(char *nptr);
int	get_time(void);
void	ft_usleep(int time);
void	*routine(void *arg);
void	end_thread(t_philo *philo, t_data *data);

#endif
