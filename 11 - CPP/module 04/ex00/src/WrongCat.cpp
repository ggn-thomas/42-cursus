/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 09:55:55 by thomas            #+#    #+#             */
/*   Updated: 2025/05/29 11:17:57 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat"){
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::~WrongCat(){
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat &cpy) : WrongAnimal() {
    if (this != &cpy)
        this->type = cpy.type;
}

WrongCat& WrongCat::operator=(const WrongCat &WrongCat){
    this->type=WrongCat.type;
    return *this;
}

void    WrongCat::makeSound() const{
    std::cout << this->getType() << " says : **wrong** miaouuu" << std::endl;
}
