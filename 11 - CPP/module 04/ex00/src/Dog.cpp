/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:43:05 by thgaugai          #+#    #+#             */
/*   Updated: 2025/05/29 10:58:11 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() : Animal("Dog"){
	std::cout << "Dog default contructor called" << std::endl;
}

Dog::Dog(Dog &cpy) : Animal() {
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &cpy)
		this->type = cpy.type;
}

Dog&	Dog::operator=(const Dog &Dog){
	this->type = Dog.type;
	return (*this);
}

Dog::~Dog(){
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << this->getType() << " says : Ouafff" << std::endl;
}