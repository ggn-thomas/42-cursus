/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:04:02 by thomas            #+#    #+#             */
/*   Updated: 2025/05/23 11:30:05 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("Default", 100, 50, 20){
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &cpy) : ClapTrap(){
    *this = cpy;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &st){
    this->name = st.name;
    this->energyPoints = st.energyPoints;
    this->hitPoints = st.hitPoints;
    this->attackDamage = st.attackDamage;
    return *this;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap destructor called" << std::endl;
}

void    ScavTrap::attack(const std::string& target){
    if (this->energyPoints <= 0)
    {
        std::cout << "ScavTrap " << this->name << " can't attack " << target << " because he's run out of energy!" << std::endl;
        return ;
    }
    else if (this->hitPoints <= 0)
    {
        std::cout << "ScavTrap " << this->name << "can't attack " << target << " because he's dead!" << std::endl;
        return ;
    }
    else
    {
        this->energyPoints--;
        std::cout << "ScavTrap " << this->name << " attacks " << target <<", causing " << this->attackDamage << " points of damage!" << std::endl;
    }
    return ;
}

void    ScavTrap::guardGate(){
    std::cout << "ScavTrap" << name << " is now in Gate keeper mode!" << std::endl;
}
