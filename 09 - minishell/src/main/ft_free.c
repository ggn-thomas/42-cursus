/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:34:04 by thgaugai          #+#    #+#             */
/*   Updated: 2025/04/02 16:57:04 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_free_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free_list(t_line **list)
{
	t_line	*remove;
	t_line	*tmp;

	tmp = *list;
	while (tmp)
	{
		remove = tmp;
		tmp = tmp->next;
		printf("Freeing node data: %p ('%s')\n", (void*)remove->data, remove->data);
		free(remove->data);
		free(remove);
	}
	free(list);
}

void	ft_free_list_cmd(t_command **list)
{
	t_command	*remove;
	t_command	*tmp;

	if (list == NULL || *list == NULL)
		return ;
	tmp = *list;
	while (tmp)
	{
		remove = tmp;
		tmp = tmp->next;
		if (remove->command)
			free(remove->command);
		if (remove->outfile)
			free(remove->outfile);
		if (remove->infile)
			free(remove->infile);
		if (remove->args)
			ft_free_list(remove->args);
		free(remove);
	}
	free(list);
}

void	ft_free_list_env(t_env_var **lst)
{
	t_env_var	*remove;
	t_env_var	*tmp;

	if (*lst == NULL)
		return ;
	tmp = *lst;
	while (tmp)
	{
		remove = tmp;
		tmp = tmp->next;
		if (remove->key)
			free(remove->key);
		if (remove->value)
			free(remove->value);
		if (remove->str)
			free(remove->str);
		free(remove);
	}
	free(lst);
}