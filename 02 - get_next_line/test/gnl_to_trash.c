/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:01:23 by thgaugai          #+#    #+#             */
/*   Updated: 2024/10/31 14:41:22 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_str(char **tmp, char *buffer)
{
    char    *str;

    if (!*tmp)
        *tmp = ft_strdup("");
    str = ft_strjoin(*tmp, buffer);
    free(*tmp);
    *tmp = NULL;
    return (str);
}

char    *ft_line(char *str)
{
    int i;
    char    *line;

    i = 0;
    line = NULL;
    while (str[i])
    {
        if (str[i] == '\n' || str[i] == '\0')
        {
            line = ft_substr(str, 0, i + 1);
            break ;
        }
        i++;
    }
    return (line);
}

char    *ft_surplus(char *str, char *line)
{
    int i = 0;
    char    *tmp;

    if (!line)
        tmp = ft_strdup(str);
    else 
    {
        while (str[i] != '\n' && str[i] != '\0')
            i++;
        tmp = ft_substr(str, i + 1, ft_strlen(str) - i - 1);
    }
    return (tmp);
}

char    *ft_fill_buffer(int fd, char *buffer)
{
    ssize_t read_byte;
    char    *str;
    char    *line;
    static char *tmp;

    read_byte = 1;
    while (read_byte > 0) 
    {
        read_byte = read(fd, buffer, BUFFER_SIZE);
        if (read_byte < 0 || (read_byte == 0 && (!tmp || !*tmp)))
        {
            if (tmp)
            {
                free(tmp);
                tmp = NULL;
            }
            return (NULL);
        }
        buffer[read_byte] = '\0';
        str = ft_str(&tmp, buffer);
        line = ft_line(str);
        tmp = ft_surplus(str, line);
        free(str);
        if (line)
            return (line);
    }
    if (tmp && *tmp) 
    {
        line = ft_strdup(tmp);
        free(tmp);
        tmp = NULL;
        return (line);
    }
    return (NULL);
}

char    *get_next_line(int fd)
{
    char    *buffer;
    char    *line;

    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (read(fd, 0, 0) < 0 || fd < 0 || BUFFER_SIZE <= 0)
    {
        free(buffer);
        buffer = NULL;
        return (NULL);
    }
    if (!buffer)
        return (NULL);
    line = ft_fill_buffer(fd, buffer);
    free(buffer);
    buffer = NULL;
    return (line);
}

/*
#include <stdio.h>

int	main()
{
    int fd;
    char *tab;

    fd = open("only_nl.txt", O_RDONLY); 

    while ((tab = get_next_line(fd)))
    {
        printf("%s", tab);
        free(tab); 
    }
    close(fd);
    return (0);
}

*/