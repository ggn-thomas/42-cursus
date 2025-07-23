/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:11:53 by thomas            #+#    #+#             */
/*   Updated: 2024/12/18 18:21:15 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static long	ft_atol(const char *nptr)
{
	int		i;
	long	nb;
	long	r;
	char	*str;

	str = (char *)nptr;
	i = 0;
	nb = 1;
	r = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	while ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i + 1] == '+' || str[i + 1] == '-')
			return (0);
		else if (nptr[i] == '-')
			nb *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - 48);
		i++;
	}
	return (r * nb);
}

static t_stack_node	*ft_new_node(int new_node)
{
	t_stack_node	*new;

	new = malloc(sizeof(t_stack_node));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->nbr = new_node;
	return (new);
}

static void	ft_add_node(t_stack_node **lst, t_stack_node *new)
{
	if (*lst)
		(*lst)->prev = new;
	new->next = *lst;
	*lst = new;
}

int	stack_start(t_stack_node **a, char **str)
{
	int				j;
	long			nbr;
	t_stack_node	*tmp;

	j = 0;
	nbr = 0;
	while (str[j])
		j++;
	while (j > 0)
	{
		nbr = ft_atol(str[j - 1]);
		if ((ft_check_double(a, nbr)) || (nbr > INT_MAX) || (nbr < INT_MIN))
		{
			free_error(str, a);
			return (0);
		}
		tmp = ft_new_node(nbr);
		ft_add_node(a, tmp);
		j--;
	}
	return (1);
}

void	stack_init(t_stack_node **stack_a, t_stack_node **stack_b)
{
	ft_find_target_node(stack_a, stack_b);
	ft_push_price(stack_a);
	ft_push_price(stack_b);
	ft_update_index(stack_a);
	ft_update_index(stack_b);
}
