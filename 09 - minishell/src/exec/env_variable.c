/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:14:34 by thgaugai          #+#    #+#             */
/*   Updated: 2025/03/31 17:25:59 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	add_var(t_env_var *new_node, t_env_var **lst_command)
{
	t_env_var	*last;

	if (!*lst_command)
	{
		*lst_command = new_node;
		return ;
	}
	last = *lst_command;
	while (last->next)
		last = last->next;
	last->next = new_node;
}

static char	*get_key(char *str)
{
	int		i;
	int		len;
	char	*var;

	len = 0;
	i = -1;
	while (str[len] != '=')
		len++;
	var = malloc(sizeof(char) * (len + 1));
	if (!var)
		return (NULL);
	while (++i < len)
		var[i] = str[i];
	var[i] = '\0';
	return (var);
}

static char	*get_value(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*var;

	i = 0;
	while (str[i] != '=')
		i++;
	i++;
	j = i;
	len = 0;
	while (str[i + len])
		len++;
	var = malloc(sizeof(char) * (len + 1));
	if (!var)
		return (NULL);
	i = 0;
	while (str[j])
		var[i++] = str[j++];
	var[i] = '\0';
	return (var);
}

static t_env_var	*new_var(char *str)
{
	t_env_var	*var;

	var = malloc(sizeof(t_env_var));
	if (!var)
		return (NULL);
	var->str = ft_strdup(str);
	var->next = NULL;
	var->key = get_key(str);
	var->value = get_value(str);
	return (var);
}

static void	init_env_vars(char **envp, t_env_var **lst_var)
{
	int			i;
	t_env_var	*new;

	i = 0;
	while (envp[i])
	{
		new = new_var(envp[i]);
		add_var(new, lst_var);
		i++;
	}
}

// static void	search_key(char *key, t_env_var **lst_var)
// {
// 	t_env_var	*index;

// 	index = *lst_var;
// 	(void)key;
// 	while(index)
// 	{
// 		printf("%s=%s\n", index->key, index->value);
// 		index = index->next;
// 	}
// }

t_env_var	**load_environment(char **envp)
{
	t_env_var	**lst_var;

	// char	*pattern = NULL;
	// int	len;
	// int	i;
	// int	j;
	// j = 0;
	// i = 1;
	// len = 0;
	lst_var = malloc(sizeof(t_env_var *));
	if (!lst_var)
		return (NULL);
	*lst_var = NULL;
	init_env_vars(envp, lst_var);
	// if (var[0] == '$')
	// {
	// 	len = ft_strlen(var) - 1;
	// 	pattern = malloc(sizeof(char) * (len + 1));
	// 	if (!pattern)
	// 		return (NULL);
	// 	while(var[i])
	// 		pattern[j++] = var[i++];
	// 	pattern[j] = '\0';
	// }
	return (lst_var);
}
