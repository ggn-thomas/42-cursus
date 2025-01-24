/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:14:45 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/24 17:41:11 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DEAD "died"

typedef struct s_data
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_think;
	int				time_to_sleep;
	long int				time_to_start;
	int				nb_philo;
	int				someone_died;
	int				meal_required;
	pthread_mutex_t	*mutex_death;
	pthread_mutex_t	*mutex_print;
	pthread_mutex_t	*fork;
}					t_data;

typedef struct s_philo
{
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	int				id;
	long int				last_meal;
	int				nb_meal;
	long int				start_time;
	int				dead;
	t_data			*dt;
	pthread_t		tid;
}					t_philo;

int					ft_atoi(char *nptr);
long int			get_time(void);
int				ft_usleep(long int time);
void				*routine(void *arg);
void				end_thread(t_philo *philo, t_data *data);
int					check_death(t_philo *philo);
void				check(t_philo *philo, t_data *dt);
void				print_action(t_philo *philo, char *action);
int					someone_died(t_data *data);

#endif
