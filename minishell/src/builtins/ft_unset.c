/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dornagol <dornagol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:45:20 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/03/31 10:05:42 by dornagol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_unset_identifier(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (0);
	i = 1;
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static int	delete_env_var(t_env_var **env_cpy, char *var_name)
{
	t_env_var	*current;
	t_env_var	*prev;

	if (!env_cpy || !*env_cpy || !var_name)
		return (1);
	current = *env_cpy;
	prev = NULL;
	while (current)
	{
		if (ft_strcmp(current->key, var_name) == 0)
		{
			if (prev)
				prev->next = current->next;
			else
				*env_cpy = current->next;
			free(current->key);
			free(current->value);
			free(current->str);
			free(current);
			return (0);
		}
		prev = current;
		current = current->next;
	}
	return (0);
}

static int	execute_unset(t_command *index, t_env_var **env_cpy)
{
	int		i;
	int		exit_status;
	char	*arg;

	i = 1;
	exit_status = 0;
	while (index->args[i])
	{
		arg = index->args[i]->data;
		if (!is_valid_unset_identifier(arg))
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(arg, 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			exit_status = 1;
		}
		else
			delete_env_var(env_cpy, arg);
		i++;
	}
	return (exit_status);
}

int	ft_unset(t_command *index, t_env_var **env_cpy)
{
	if (!index || !env_cpy || !*env_cpy)
		return (1);
	if (!index->args[1])
		return (0);
	return (execute_unset(index, env_cpy));
}