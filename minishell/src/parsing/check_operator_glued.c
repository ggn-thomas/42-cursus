/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operator_glued.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:49:00 by thgaugai          #+#    #+#             */
/*   Updated: 2025/04/02 16:52:35 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	add_before_op(char *str, int len, t_line **line, char **tab_line)
{
	char	*tmp;
	t_line	*new_node;

	tmp = malloc(len + 1);
	if (!tmp)
		return (0);
	ft_strncpy(tmp, str, len);
	tmp[len] = '\0';
	new_node = ft_new_node(tmp);
	if (!new_node)
		error(MALLOC, tab_line, line, NULL);
	check_type(new_node);
	ft_lst_add_back(line, new_node);
	free(tmp);
	return (1);
}

static int	add_next_op(char *str, int i, t_line **line, char **tab_line)
{
	char	*tmp;
	t_line	*new_node;
	int		n;

	n = i + 1;
	while (str[n] != '|' && str[n] != '<' && str[n] != '>' && str[n])
		n++;
	tmp = ft_strndup(&str[i + 1], n - i - 1);
	if (tmp && tmp[0] != '\0')
	{
		new_node = ft_new_node(tmp);
		if (!new_node)
			error(MALLOC, tab_line, line, NULL);
		check_type(new_node);
		ft_lst_add_back(line, new_node);
		free(tmp);
	}
	else if (tmp)
		free(tmp);
	return (n - i);
}

static void	add_operator_s(char operator, t_line ** line, char **tab_line)
{
	t_line	*new_node;
	char	tab_operator[2];

	tab_operator[0] = operator;
	tab_operator[1] = '\0';
	new_node = ft_new_node(tab_operator);
	if (!new_node)
		error(MALLOC, tab_line, line, NULL);
	check_type(new_node);
	ft_lst_add_back(line, new_node);
}

static void	add_operator_d(char operator, t_line ** line, char **tab_line)
{
	t_line	*new_node;
	char	tab_operator[3];

	tab_operator[0] = operator;
	tab_operator[1] = operator;
	tab_operator[2] = '\0';
	new_node = ft_new_node(tab_operator);
	if (!new_node)
		error(MALLOC, tab_line, line, NULL);
	check_type(new_node);
	ft_lst_add_back(line, new_node);
}

static int	skip_first_operator(char *str, t_line **line, char **tab_line)
{
	int	i;

	i = 0;
	while (str[i] == '|' || str[i] == '<' || str[i] == '>')
	{
		if (str[i + 1] == str[i] && str[i] != '|')
		{
			add_operator_d(str[i], line, tab_line);
			i++;
		}
		else
			add_operator_s(str[i], line, tab_line);
		i++;
	}
	return (i);
}

t_line	**check_operator_glued(char *str, t_line **line, char **tab_line)
{
	int	i;
	int	n;

	n = 0;
	i = skip_first_operator(str, line, tab_line);
	if (!str[i])
		return (line);
	while (str[i] != '|' && str[i] != '<' && str[i] != '>' && str[i])
		i++;
	add_before_op(str, i, line, tab_line);
	while (str[i])
	{
		while (str[i] != '|' && str[i] != '<' && str[i] != '>' && str[i])
			i++;
		if (str[i + 1] == str[i])
			add_operator_d(str[i++], line, tab_line);
		else
			add_operator_s(str[i], line, tab_line);
		n = add_next_op(str, i, line, tab_line);
		i += n;
	}
	return (line);
}
