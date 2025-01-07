/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:20:05 by thgaugai          #+#    #+#             */
/*   Updated: 2025/01/07 18:07:47 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

#include <stdio.h>
void	translate_message(int signint)
{
	static int	counter = 0;
	static char	*message = NULL;
	static char	char_received = 0;
	char	tmp[2];

	if (!message)
		message = ft_strdup("");
	char_received <<= 1;
	if (signint == SIGUSR1)
		char_received |= 1;
	counter++;
	if (counter == 8)
	{
		tmp[0] = char_received;
		tmp[1] = '\0';
		message = ft_strjoin(message, tmp);
		if (char_received == '\0')
		{
			ft_putstr_fd(message, 1);
			ft_putchar_fd('\n', 1);
			free(message);
			message = NULL;
		}
		char_received = 0;
		counter = 0;
	}
}

void handle_signint(int signint)
{
	if (signint == SIGUSR1 || signint == SIGUSR2)
		translate_message(signint);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t	pid_server;

	pid_server = getpid();
	ft_putstr_fd("Server pid : ", 1);
	ft_putnbr_fd((int)pid_server, 1);
	ft_putchar_fd('\n', 1);
	sa.sa_handler = handle_signint;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
	return (0);
}
