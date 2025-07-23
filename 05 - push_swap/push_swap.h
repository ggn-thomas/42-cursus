/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:03:39 by thgaugai          #+#    #+#             */
/*   Updated: 2024/12/03 11:36:42 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;
void					ft_update_index(t_stack_node **lst);
t_stack_node			*ft_lst_last(t_stack_node **lst);
int						ft_lstlen(t_stack_node **lst);
t_stack_node			*ft_biggest(t_stack_node **lst);
t_stack_node			*ft_smallest(t_stack_node **lst);
void					ft_find_target_node(t_stack_node **stack_a,
							t_stack_node **stack_b);
t_stack_node			**ft_push_price(t_stack_node **lst);
void					stack_moves(t_stack_node **stack_a,
							t_stack_node **stack_b);
t_stack_node			**ft_push_swap(t_stack_node **stack_a,
							t_stack_node **stack_b);
t_stack_node			**ft_sort_3(t_stack_node **lst);
t_stack_node			**ft_sort_2(t_stack_node **lst);
void					stack_init(t_stack_node **stack_a,
							t_stack_node **stack_b);
int						stack_start(t_stack_node **a, char **str);
int						ft_valid_syntax(char **str);
int						ft_check_double(t_stack_node **lst, int nbr);
void					ft_free_split(char **str);
void					free_error(char **str, t_stack_node **lst);
void					ft_free_stack(t_stack_node **lst);
void					rra(t_stack_node **lst);
void					rrb(t_stack_node **lst);
void					rrr(t_stack_node **stack_a, t_stack_node **stack_b);
void					ra(t_stack_node **lst);
void					rb(t_stack_node **lst);
void					rr(t_stack_node **stack_a, t_stack_node **stack_b);
void					sa(t_stack_node **lst);
void					sb(t_stack_node **lst);
void					ss(t_stack_node **stack_a, t_stack_node **stack_b);
void					pa(t_stack_node **lst_src, t_stack_node **lst_dest);
void					pb(t_stack_node **lst_src, t_stack_node **lst_dest);
#endif
