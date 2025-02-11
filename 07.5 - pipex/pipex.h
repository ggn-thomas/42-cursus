/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:41:49 by thomas            #+#    #+#             */
/*   Updated: 2025/02/11 15:47:30 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char    *ft_strjoin(char const *s1, char const *s2);
char	*find_path(char **envp, char *command);
char    open_file(int fd);

#endif