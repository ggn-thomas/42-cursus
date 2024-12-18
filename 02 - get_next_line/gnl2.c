/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:06:56 by thomas            #+#    #+#             */
/*   Updated: 2024/10/30 17:38:55 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



char    *ft_surplus(char *str, char *line)
{
    int i;
    char    *tmp;

    i = 0;
    if (line == NULL)
        tmp = ft_strdup(str);
    else
    {
        while ((str[i] != '\n') && (str[i] != '\0'))
            i++;
        tmp = ft_substr(str, i + 1, BUFFER_SIZE - i);
    }
    return (tmp);
}

char	*ft_str(char **tmp, char *buffer)
{
	char	*str;

	str = ft_strjoin(*tmp, buffer);
	if (!str)
		return (NULL);
	return (str);
}
char   *ft_line(char *buffer, char **tmp, int read_byte)
{
    char    *line;
    char    *str;
    int i;

    buffer[read_byte] = '\0';
    if (!*tmp)
        *tmp = ft_strdup("");
		if (!tmp)
			return (NULL);
    str = ft_str(*tmp, buffer);
    free(*tmp);
		free(buffer);
    line = NULL;
    *tmp = NULL;
		i = 0;
    while (str[i])
    {
        if (str[i] == '\n' || str[i] == '\0')
        {
            line = ft_substr(str, 0, i + 1);
            break ;
        }
        i++;
    }
    *tmp = ft_surplus(str, line);
    free(str);
    return (line);
}
char    *get_next_line(int fd)
{
    char    *buffer;
    char    *line;
    int read_byte;
    static char *tmp;

    read_byte = 1;
    while (read_byte > 0)
    {
        buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (!buffer)
            return (NULL);
        if (fd < 0 || BUFFER_SIZE <= 0)
        {
            free(buffer);
            buffer = NULL;
            break ;
        }
        read_byte = read(fd, buffer, BUFFER_SIZE);
        if (read_byte == -1)
        {
            free(buffer);
            buffer = NULL;
            return (NULL);
        }
        line = ft_line(buffer, &tmp, read_byte);
        if (line != NULL)
            return (line);
    }
    if (tmp)
    {
        free(tmp);
        tmp = NULL;
    }
    return (0);
}

#include <stdio.h>

int	main()
{
    int fd;
    char *tab;

    fd = open("test.txt", O_RDONLY); 

    while ((tab = get_next_line(fd)))
    {
        printf("%s", tab);
        free(tab); 
    }
    close(fd);
    return (0);
}


