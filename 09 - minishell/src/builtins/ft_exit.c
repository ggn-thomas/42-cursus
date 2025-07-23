/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:38:44 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/03/31 16:54:46 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_exit(t_command **list)
{
	// int	i;

	// i = 0;
	// if (list->command)
	// {}
	// if (list->command == 1)
	// {}
	ft_free_list_cmd(list);
	printf("exit\n");
	exit(EXIT_SUCCESS);
}

// 0 - Sucess
// 1 - General Error
// 2 - Syntax Error
// 126 - Command non executable
// 127 - Command not found