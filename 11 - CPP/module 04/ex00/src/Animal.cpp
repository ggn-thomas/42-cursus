/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:26:13 by thgaugai          #+#    #+#             */
/*   Updated: 2025/05/29 11:20:48 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal(){
	std::cout << "Animal default constructor called" << std::endl;
	this->type = "Default";
}

Animal::Animal(std::string type){
	std::cout << "Animal default constructor called" << std::endl;
	this->type = type;
}

Animal::Animal(Animal &cpy){
	std::cout << "Copy assignment operator called" << std::endl;
	this->type = cpy.type;
}

Animal& Animal::operator=(const Animal &a){
	this->type = a.type;
	return (*this);
}

Animal::~Animal(){
	std::cout << "Animal destructor called" << std::endl;
}

void	Animal::makeSound() const{
	std::cout << "Default Animal sound" << std::endl;
}

std::string	Animal::getType() const{
	return this->type;
}