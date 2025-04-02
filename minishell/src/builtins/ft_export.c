/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:44:18 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/03/31 17:36:05 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	print_export_error(char *arg)
{
	ft_putstr_fd("export: `", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	return (1);
}

static t_env_var	*find_env_var(t_env_var **env_list, char *key)
{
	t_env_var	*current;

	current = *env_list;
	while (current)
	{
		if (ft_strcmp(current->key, key) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}

static int	update_env_var(t_env_var *var, char *key, char *value)
{
	if (value)
	{
		free(var->value);
		var->value = ft_strdup(value);
		if (!var->value)
			return (1);
		free(var->str);
		var->str = ft_strjoin(key, "=");
		if (!var->str)
			return (1);
		var->str = ft_strjoin(var->str, value);
		if (!var->str)
			return (1);
	}
	return (0);
}

static t_env_var	*create_env_var(char *key, char *value)
{
	t_env_var	*new_var;

	new_var = malloc(sizeof(t_env_var));
	if (!new_var)
		return (NULL);
	new_var->key = ft_strdup(key);
	if (!new_var->key)
	{
		free(new_var);
		return (NULL);
	}
	new_var->next = NULL;
	if (value)
	{
		new_var->value = ft_strdup(value);
		if (!new_var->value)
		{
			free(new_var->key);
			free(new_var);
			return (NULL);
		}
		new_var->str = ft_strjoin(key, "=");
		new_var->str = ft_strjoin(new_var->str, value);
	}
	else
	{
		new_var->value = NULL;
		new_var->str = ft_strdup(key);
	}
	return (new_var);
}

static int	add_or_update_var(t_env_var **env_list, char *key, char *value)
{
	t_env_var	*var;
	t_env_var	*new_var;

	var = find_env_var(env_list, key);
	if (var)
		return (update_env_var(var, key, value));
	else
	{
		new_var = create_env_var(key, value);
		if (!new_var)
			return (1);
		if (!new_var->str)
		{
			free(new_var->key);
			if (new_var->value)
				free(new_var->value);
			free(new_var);
			return (1);
		}
		if (*env_list == NULL)
			*env_list = new_var;
		else
			add_var(new_var, env_list);
	}
	return (0);
}

static int	parse_export_arg(char *arg, t_env_var **env_list)
{
	char	*equal_sign;
	char	*key;
	char	*value;
	int		result;

	equal_sign = ft_strchr(arg, '=');
	if (!equal_sign)
		return (add_or_update_var(env_list, arg, NULL));
	key = malloc((equal_sign - arg) + 1);
	if (!key)
		return (1);
	ft_strlcpy(key, arg, (equal_sign - arg) + 1);
	value = ft_strdup(equal_sign + 1);
	if (!value && *(equal_sign + 1) != '\0')
	{
		free(key);
		return (1);
	}
	result = add_or_update_var(env_list, key, value);
	free(key);
	if (value)
		free(value);
	return (result);
}

int	ft_export(t_command *cmd, t_env_var **env_list)
{
	int		i;
	int		ret;
	char	**args;
	t_line	**line_args;

	ret = 0;
	if (!cmd || !env_list || !cmd->args)
		return (1);
	line_args = cmd->args;
	i = 0;
	while (line_args[i])
		i++;
	printf("%d\n", i); // Taille des arguments
	args = malloc(sizeof(char *) * (i + 1));
	if (!args)
		return (1);
	i = 0;
	while (line_args[i])
	{
		args[i] = line_args[i]->data;
		i++;
	}
	args[i] = NULL;
	i = 0;
	// printf("%s\n", args[0]); // Juste des tests pour check les args
	// printf("%s\n", args[1]);
	while (args[i])
	{
		if (!is_valid_identifier(args[i]))
			ret = print_export_error(args[i]);
		else if (parse_export_arg(args[i], env_list))
			ret = 1;
		i++;
	}
	free(args);
	return (ret);
}
