/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:37:30 by thgaugai          #+#    #+#             */
/*   Updated: 2025/02/18 11:04:18 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int	main(void)
{
	char	*rl;
	HIST_ENTRY	**history;

	rl = readline("-> bash");
	printf("%s\n", rl);
	add_history(rl);
	free(rl);

	rl_on_new_line();

	rl_clear_history();
	return (0);
}