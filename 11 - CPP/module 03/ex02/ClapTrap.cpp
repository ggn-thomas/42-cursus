/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:46:18 by thomas            #+#    #+#             */
/*   Updated: 2025/05/26 17:04:48 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
    std::cout << "ClapTrap default constructor called" << std::endl;
    this->name = "Default";
    this->energyPoints = 10;
    this->hitPoints = 10;
    this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name){
    std::cout << "ClapTrap default constructor called" << std::endl;
    this->name = name;
    this->energyPoints = 10;
    this->hitPoints = 10;
    this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage){
    std::cout << "ClapTrap default constructor called" << std::endl;
    this->name = name;
    this->attackDamage = attackDamage;
    this->energyPoints = energyPoints;
    this->hitPoints = hitPoints;
}

ClapTrap::ClapTrap(const ClapTrap &cpy){
    std::cout << "Copy assignment operator called" << std::endl;
    *this = cpy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &ct){
    this->name = ct.name;
    this->energyPoints = ct.energyPoints;
    this->hitPoints = ct.hitPoints;
    this->attackDamage = ct.attackDamage;
    return (*this);
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap destructor called" << std::endl;
}

void    ClapTrap::attack(const std::string& target){
    if (this->energyPoints <= 0)
    {
        std::cout << "ClapTrap " << this->name << " can't attack " << target << " because he's run out of energy." << std::endl;
        return ;
    }
    else if (this->hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->name << " can't attack " << target << " because he's dead." << std::endl;
        return ;
    }
    else
    {
        this->energyPoints--;
        std::cout << "ClapTrap " << this->name << " attacks " << target <<", causing " << this->attackDamage << " points of damage!" << std::endl;
    }
    return ;
}

void    ClapTrap::takeDamage(unsigned int amount){
    int tmp = this->hitPoints;
    
    if (this->hitPoints <= 0)
        std::cout << "ClapTrap "<< this->name << " is dead!" << std::endl;
    else
    {
        tmp-=amount;
        if (tmp < 0)
            this->hitPoints = 0;
        else
            this->hitPoints -= amount;
        std::cout << "ClapTrap "<< this->name << " a has been damaged, so it now has " << this->hitPoints << " hit points." <<std::endl;
    }
    return ;
}

void    ClapTrap::beRepaired(unsigned int amount){
    if (this->energyPoints <= 0)
    {
        std::cout << "ClapTrap " << this->name << " doesn't have enough energy to repair itself." << std::endl;
        return ;
    }
    else
    {
        this->energyPoints--;
        this->hitPoints += amount;
        std::cout << "ClapTrap " << this->name << " it's fixed, so now he has " << this->hitPoints << " hit points." << std::endl;
    }
    return ;
}

unsigned int    ClapTrap::getDamage(){
    return this->attackDamage;
}

unsigned int    ClapTrap::getHitPoints(){
    return this->hitPoints;
}

unsigned int ClapTrap::getEnergyPoints(){
    return this->energyPoints;
}

std::string ClapTrap::getName(){
    return this->name;
}
