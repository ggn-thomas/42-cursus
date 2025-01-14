/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:49:19 by thomas            #+#    #+#             */
/*   Updated: 2025/01/11 18:19:34 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

size_t  ft_strlen(char *str)
{
    size_t  i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void    capitalizer(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (i == 0 && (str[i] => 'a' && str[i] <= 'z'))
            str[i] -= 32;
        else if ((i - 1 == ' ' || i - 1 == '\t') && (str[i] >= 'a' && str[i] <= 'z'))
            str[i] -= 32;
        else if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        write (1, &str[i], 1);
        i++;
    }
    write(1, '\n', 1);
}

void    one_letter(char c)
{
    if (c >= 'a' && c <= 'z')
        c -= 32;
    write(1, &c, 1);
    return ;
}

void    str_capitalizer(const char *str, ...)
{
    va_list args;
    
    if (!str)
        return (0);
    va_start(args, str);
    while (args)
    {
        if (ft_strlen(args) == 1)
            one_letter(args);
        capitalizer(args);
        va_arg(args, str);
    }
    va_end(args);
    return (0);
}

int main(int ac, char **av)
{
    str_capitalizer(av[1]);
}