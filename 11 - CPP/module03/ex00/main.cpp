/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:46:38 by thomas            #+#    #+#             */
/*   Updated: 2025/05/16 12:02:34 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(){
    ClapTrap    Thomas("Thomas");

    Thomas.attack("Doc");
    Thomas.takeDamage(Thomas.getDamage());
    Thomas.beRepaired(1);
    for (int i = 0; i < 14; i++)
    {
        Thomas.attack("Thomas");
        Thomas.takeDamage(Thomas.getDamage());
    }
    return (0);
    
}