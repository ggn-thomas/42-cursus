/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:20:05 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/06 15:48:12 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	translate_message(int signint)
{
	int	counter;
	static char	*char_received;
	char	*message;

	message = ft_strdup("");
	while (counter != 8)
	{
		if (signint == SIGUSR1)
			char_received = char_received << 1;
		counter++;
	}
	if (counter == 8)
	{
		message = ft_strjoin(message, char_received);
		counter = 0;
	}
}

void	handle_signint(int signint)
{
	if (signint == SIGUSR1 || signint == SIGUSR2)
		translate_message(signint);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t	pid_server;

	pid_server = getpid();
	ft_printf("Server pid : %d\n", pid_server);
	sa.sa_sigaction = handle_signint;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
