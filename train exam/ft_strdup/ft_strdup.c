/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:40:36 by thomas            #+#    #+#             */
/*   Updated: 2025/01/11 17:47:20 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t  ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *ft_strdup(char *str)
{
    size_t len;
    char    *dest;
    int i;
    
    if (!str)
        return (NULL);
    i = 0;
    len = ft_strlen(str);
    dest = malloc(sizeof(char) * (len + 1));
    if (!dest)
        return (NULL);
    while (str[i])
    {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);   
}