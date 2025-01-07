/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:19:54 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/07 18:14:56 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

void	ft_send_message(pid_t pid, char *message)
{
	int	i;
	unsigned int	j;

	i = 0;
	j = 0;
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
}

int	main(int ac, char **av)
{
	pid_t	pid_server;
	(void)ac;
	if (ac != 3 || !ft_strlen(av[2]))
		return (1);
	pid_server = (pid_t)ft_atoi(av[1]);
	ft_send_message(pid_server, av[2]);
	while (1)
		pause();
	return (0);
}