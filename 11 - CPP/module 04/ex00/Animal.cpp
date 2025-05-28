/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:26:13 by thgaugai          #+#    #+#             */
/*   Updated: 2025/05/28 11:42:35 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.cpp"

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
	*this = cpy;
}

Animal& Animal::operator=(const Animal &a){
	this->name = a.name;
	return (*this);
}

Animal::~Animal(){
	std::cout << "Destructor called" << std::endl;
}

Animal::makeSound(){
	if (this->name == "Cat")
		std::cout << "Miaouuuu" << std::endl;
	else if (this->name == "Dog")
		std::cout << "Waoufff" << std::endl;
	else
		return;
}