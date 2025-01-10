/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:19:54 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/09 13:01:08 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	check_reception(int signint)
{
	static int	counter = 0;

	if (signint == SIGUSR1)
		counter++;
	else if (signint == SIGUSR2)
	{
		ft_putstr_fd("The message has been correctly received by ", 1);
		ft_putstr_fd("the server, the number of character was ", 1);
		ft_putnbr_fd(counter, 1);
		ft_putchar_fd('\n', 1);
		counter = 0;
		exit(0);
	}
}

void	ft_send_message(pid_t pid, char *message)
{
	int				i;
	unsigned int	j;

	i = 0;
	while (message[i])
	{
		j = 0;
		while (j < 8 * sizeof(char))
		{
			if ((message[i] >> (7 - j)) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
			usleep(100);
		}
		i++;
	}
	j = 0;
	while (j < 8)
	{
		kill(pid, SIGUSR2);
		j++;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	pid_t	pid_server;

	if (ac != 3 || !ft_strlen(av[2]))
		return (1);
	pid_server = (pid_t)ft_atoi(av[1]);
	signal(SIGUSR1, check_reception);
	signal(SIGUSR2, check_reception);
	ft_send_message(pid_server, av[2]);
	while (1)
		pause();
	return (0);
}
