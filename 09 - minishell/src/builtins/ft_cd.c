/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:10:29 by dornagol          #+#    #+#             */
/*   Updated: 2025/03/20 10:06:33 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int ft_cd(t_command *index)
{
	if (!*index->args)
		chdir(getenv("HOME"));
	else if (chdir((*index->args)->data) != 0)
	{
		perror("cd failed");
		return (1);
	}
	return (0);
}

// Gerer le "cd .."
// Gerer le "cd ."
// Proteger "getcwd"
