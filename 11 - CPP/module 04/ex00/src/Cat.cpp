/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:05:24 by thgaugai          #+#    #+#             */
/*   Updated: 2025/05/29 10:57:55 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat"){
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(Cat &cpy) : Animal() {
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &cpy)
		this->type = cpy.type;
}

Cat&	Cat::operator=(const Cat &Cat){
	this->type = Cat.type;
	return (*this);
}

void	Cat::makeSound() const {
	std::cout << this->getType() << " says : Miaouuuu" << std::endl;
}
