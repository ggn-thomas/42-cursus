/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:02:51 by thgaugai          #+#    #+#             */
/*   Updated: 2025/07/22 13:55:35 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**str;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	argc -= 1;
	while (argc > 0)
	{
		str = ft_split(argv[argc--], ' ');
		if (!(ft_valid_syntax(str)))
		{
			free_error(str, &a);
			return (0);
		}
		if (!(stack_start(&a, str)))
			return (0);
		ft_free_split(str);
	}
	ft_update_index(&a);
	ft_push_swap(&a, &b);
	ft_free_stack(&a);
	return (0);
}
