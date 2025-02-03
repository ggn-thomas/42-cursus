/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:14:45 by thgaugai          #+#    #+#             */
/*   Updated: 2025/02/03 14:06:51 by thgaugai         ###   ########.fr       */
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
# define ERROR "The arguments are not correct !"

typedef struct s_data
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_think;
	int				time_to_sleep;
	long int		start;
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
	int				nb_meal;
	long int		last_meal;
	long int		thread_start;
	int				dead;
	t_data			*dt;
	pthread_t		tid;
}					t_philo;

long				ft_atoi(char *nptr);
long int			get_time(void);
int					ft_usleep(long int time);
void				*routine(void *arg);
void				end_thread(t_philo *philo, t_data *data);
void				check(t_philo *philo, t_data *dt);
void				print_action(t_philo *philo, char *action);
int					check_parsing(char **str);
int					error(char *str, t_data *dt, t_philo *ph, int malloc);
int					thread_init(t_data *data, t_philo *ph);
int					mutex_init(t_data *data);
t_data				*var_init(char **av);
t_philo				*philo_init(t_data *data);
#endif
