/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:44:43 by thgaugai          #+#    #+#             */
/*   Updated: 2025/05/23 13:32:42 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("Default", 100, 100, 30){
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30) {
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage) : ClapTrap(name, hitPoints, energyPoints, attackDamage){
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap &cpy) : ClapTrap() {
	*this = cpy;
}

FragTrap& FragTrap::operator=(const FragTrap &ft){
	this->name = ft.name;
	this->hitPoints = ft.hitPoints;
	this->energyPoints = ft.energyPoints;
	this->attackDamage = ft.attackDamage;
	return *this;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "High fives guys !" << std::endl;
}