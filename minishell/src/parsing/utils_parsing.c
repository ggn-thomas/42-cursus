/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:10:38 by thgaugai          #+#    #+#             */
/*   Updated: 2025/04/02 16:56:42 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_line	*ft_new_node(char *content)
{
	t_line	*new_node;

	printf("Creating node for: '%s'\n", content);
	new_node = malloc(sizeof(t_line));
	if (!new_node)
		return(NULL);
	new_node->next = NULL;
	new_node->data = ft_strdup(content);
	printf("Allocated node data: %p for '%s'\n", (void*)new_node->data, content);
	new_node->mode = 0;
	return (new_node);
}

t_line	*ft_lst_last(t_line *lst)
{
	t_line	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	if (!tmp->next)
		return (tmp);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_lst_add_back(t_line **lst, t_line *new)
{
	t_line	*last ;

	if (!lst || !new)
		return ;
	last = ft_lst_last(*lst);
	if (!last)
		*lst = new ;
	else
		last->next = new ;
}

int	had_token_in_list(char *tab_line, t_line **list_token)
{
	t_line	*tmp;

	tmp = ft_new_node(tab_line);
	if (!tmp)
		return (0);
	check_type(tmp);
	ft_lst_add_back(list_token, tmp);
	return (1);
}

int	have_operator_glued(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '|' || str[i] == '>' || str[i] == '<') && ft_strlen(str) > 1)
			return (1);
		i++;
	}
	return (0);
}
