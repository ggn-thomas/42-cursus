/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:11:30 by thomas            #+#    #+#             */
/*   Updated: 2025/05/10 16:44:45 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}


void    HumanB::setWeapon(Weapon& weapon){
    this->weapon = &weapon;
}

void    HumanB::attack() {
    if (this->weapon)
        std::cout << name << " attack with their " << weapon->getType() << std::endl;
    else
        return ;
    return ;
}
