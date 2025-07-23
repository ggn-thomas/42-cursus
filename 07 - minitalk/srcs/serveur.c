/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:20:05 by thgaugai          #+#    #+#             */
/*   Updated: 2025/07/22 14:52:35 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	handle_signint(int signint)
{
	static int				counter = 0;
	static unsigned char	char_received = 0;

	char_received |= (signint == SIGUSR1);
	counter++;
	if (counter == 8)
	{
		counter = 0;
		ft_putchar_fd(char_received, 1);
		char_received = 0;
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
	sa.sa_handler = handle_signint;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
	return (0);
}
