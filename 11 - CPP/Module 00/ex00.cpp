/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:54:12 by thomas            #+#    #+#             */
/*   Updated: 2025/04/22 11:39:42 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int main(int ac, char **av)
{
    int i = 1;
    int j = 0;
    while (av[i])
    {
        j = 0;
        while (av[i][j])
        {
            if (av[i][j] >= 'a' && av[i][j] <= 'z')
                av[i][j] -= 32;
            j++;
        }
        cout << av[i++];
        if (av[i])
            cout << ' ';
    }
    return 0;
}