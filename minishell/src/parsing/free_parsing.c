/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:46:17 by thomas            #+#    #+#             */
/*   Updated: 2025/03/31 17:11:38 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	error(char *error_msg, char **tab_line, t_line **list_token,
		t_command **lst_cmd)
{
	if (tab_line)
		ft_free_tab(tab_line);
	if (list_token)
		ft_free_list(list_token);
	if (lst_cmd)
		ft_free_list_cmd(lst_cmd);
	printf("%s\n", error_msg);
	exit(EXIT_FAILURE);
}

void	error_h(char *error_msg, t_line	**line, t_line **list_token,
	t_command **lst_cmd)
{
	error(error_msg, NULL, list_token, lst_cmd);
	ft_free_list(line);
}

void	error_l(char *error_msg, t_command **lst_cmd, t_env_var **env_cpy)
{
	if (lst_cmd)
		ft_free_list_cmd(lst_cmd);
	if (env_cpy)
		ft_free_list_env(env_cpy);
	printf("%s\n", error_msg);
	exit(EXIT_FAILURE);
}
