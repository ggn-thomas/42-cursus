/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:04:38 by dornagol          #+#    #+#             */
/*   Updated: 2025/03/12 18:32:55 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// void	builtins(char *cmd)
// {
// 	if (ft_strlen(cmd) > 1)
// 	{
// 		char **args;
// 		args = ft_split(cmd, ' ');
// 		if (ft_strcmp(args[0], "cd") == 0)
// 			ft_cd(args[1]);
// 		else if (ft_strcmp(args[0], "pwd") == 0)
// 			ft_pwd();
// 		else if (ft_strcmp(args[0], "echo") == 0)
// 			ft_echo(args);
// 	}
// }

// int is_builtin(char *cmd)
// {
// 	if (ft_strcmp(cmd, "echo") == 0 || ft_strcmp(cmd, "cd") == 0 ||
// 		ft_strcmp(cmd, "pwd") == 0 || ft_strcmp(cmd, "exit") == 0 ||
// 		ft_strcmp(cmd, "env") == 0 || ft_strcmp(cmd, "export") == 0 ||
// 		ft_strcmp(cmd, "unset") == 0)
// 		return (1);
// 	return (0);
// }