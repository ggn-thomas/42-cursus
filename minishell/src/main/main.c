/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:49:39 by thgaugai          #+#    #+#             */
/*   Updated: 2025/03/31 17:37:49 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(int argc, char **argv, char **env)
{
	t_command			**list_command;
	char				*rl;
	struct sigaction	sa;
	t_env_var			**env_cpy;

	(void)argc;
	(void)argv;
	sa.sa_handler = signal_handler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, 0);
	env_cpy = load_environment(env);
	while (1)
	{
		rl = readline("-> minishell > ");
		if (!rl)
			break ;
		if (ft_strlen(rl))
		{
			list_command = sort_arguments(rl, env_cpy);
			add_history(rl);
			ft_free_list_cmd(list_command);
		}
		free(rl);
	}
	ft_free_list_env(env_cpy);
	return (0);
}
