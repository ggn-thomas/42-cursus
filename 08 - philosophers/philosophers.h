/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:14:45 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/14 09:14:48 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>// ! à retirer !

typedef struct	s_data
{
	int	time_to_die;
	int	time_to_eat;
	int	time_to_think;
	int	time_to_sleep;
	int	nb_philo;
}	t_data;

typedef struct	s_philo
{
	int	id;
	t_data	dt;
}	t_philo;


//utils
int	ft_atoi(char *nptr);

#endif
