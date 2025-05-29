/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 09:44:16 by thomas            #+#    #+#             */
/*   Updated: 2025/05/29 11:16:22 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
    std::cout << "WrongAnimal default constructor called" << std::endl;
    this->type = "Default";
}

WrongAnimal::WrongAnimal(std::string type){
    std::cout << "WrongAnimal default constructor called" << std::endl;
    this->type = type;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &copy){
    if (this != &copy)
        this->type = copy.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &WrongAnimal){
    this->type = WrongAnimal.type;
    return *this;
}

void    WrongAnimal::makeSound() const{
    std::cout <<"**Default WrongAnimal sound**" << std::endl;
}

std::string    WrongAnimal::getType() const{
    return this->type;
}
