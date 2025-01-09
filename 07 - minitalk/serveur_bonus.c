/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:20:05 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/09 09:43:46 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signint(int signint, siginfo_t *info, void *context)
{
	static int				counter = 0;
	static unsigned char	char_received = 0;
	static pid_t			pid_client = 0;

	(void)context;
	if (!pid_client)
		pid_client = info->si_pid;
	char_received |= (signint == SIGUSR1);
	if (++counter == 8)
	{
		counter = 0;
		if (!char_received)
		{
			kill(pid_client, SIGUSR2);
			pid_client = 0;
			return ;
		}
		ft_putchar_fd(char_received, 1);
		char_received = 0;
		kill(pid_client, SIGUSR1);
	}
	else
		char_received <<= 1;
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid_server;

	pid_server = getpid();
	ft_putstr_fd("Server pid : ", 1);
	ft_putnbr_fd(pid_server, 1);
	ft_putchar_fd('\n', 1);
	sa.sa_sigaction = handle_signint;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
	return (0);
}
