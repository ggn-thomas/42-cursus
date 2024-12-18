/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:49:49 by fben-ham          #+#    #+#             */
/*   Updated: 2024/07/31 16:41:07 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_stock_max	s_stock_max ;
struct s_stock_max
{
	int	size;
	int	x;
	int	y;
};

size_t	get_file_size(char *filename);
void	run_prog(int fd, size_t size);
char	**create_tab(char *buffer);
void	search_number(char *buffer);
char	**fill_tab(char **tab, char *buffer);
int		count_line(char *buffer);

#endif
