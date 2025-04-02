/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:15:55 by dornagol          #+#    #+#             */
/*   Updated: 2025/03/20 09:43:05 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void ft_echo(t_command *index)
{
	int		newline;
	t_line	*tmp;
	int		i;

	tmp = *index->args;
	newline = 1;
	i = 1;
	while (tmp && tmp->data[0] == '-')
	{
		while (tmp->data[i] == 'n')
			i++;
		if (tmp->data[i] == '\0')
		{
			newline = 0;
			tmp = tmp->next;
		}
		else
			break;
		i = 1;
	}
	while (tmp)
	{
		if (tmp->data[0] == '"')
			tmp->data = ft_substr(tmp->data, 1, (ft_strlen(tmp->data) - 2));
		printf("%s", tmp->data);
		if (tmp->next)
			printf(" ");
		tmp = tmp->next;
	}
	if (newline)
		printf("\n");
}
