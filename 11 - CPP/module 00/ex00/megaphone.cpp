/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:54:12 by thomas            #+#    #+#             */
/*   Updated: 2025/04/28 18:50:37 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int main(int ac, char **av)
{
    int i = 1;
    int j = 0;

    if (ac == 0)
        return 0;
    while (av[i])
    {
        j = 0;
        while (av[i][j])
        {
            if (av[i][j] >= 'a' && av[i][j] <= 'z')
                av[i][j] -= 32;
            j++;
        }
        j = 0;
        if (av[i][j] == ' ')
            j++;
        while (av[i][j])
        {
            if (!av[i][j + 1] && av[i][j] == ' ')
                break;
            else
                cout << av[i][j];
            j++;
        }
        if (av[i])
            cout << ' ';
        i++;
    }
    return 0;
}