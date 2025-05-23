/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:46:38 by thomas            #+#    #+#             */
/*   Updated: 2025/05/16 15:34:11 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(){
    ScavTrap    ScavTrap;

    ScavTrap.attack("Denis");
    ScavTrap.takeDamage(ScavTrap.getDamage());
    ScavTrap.beRepaired(10);
    ScavTrap.guardGate();
    return 0;
}