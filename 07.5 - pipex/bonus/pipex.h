/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:41:49 by thomas            #+#    #+#             */
/*   Updated: 2025/02/27 15:32:52 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

int	**init_fd(int count_pipe);
int	*init_tab_pid(int count_command);
void	ft_execute(char **envp, char *command);
int	open_file(char *file, int mode);
char	*find_path(char **envp, char *command);

#endif