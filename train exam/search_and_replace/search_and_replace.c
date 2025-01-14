/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:26:39 by thomas            #+#    #+#             */
/*   Updated: 2025/01/11 17:37:09 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    search_and_replace(char *str, char replace, char new_character)
{
    int i;

    i = 0;
    while(str[i])
    {
        if (str[i] == replace)
        {
            write(1, &new_character, 1);
            i++;
        }
        else
        {
            write(1, &str[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}


int main(int ac, char **av)
{
    if (ac != 4 || av[2][1])
    {
        write(1, "\n", 1);
        return (0);
    }
    search_and_replace(av[1], av[2][0], av[3][0]);
}