/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:20:29 by thomas            #+#    #+#             */
/*   Updated: 2025/08/25 16:40:06 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){
    std::cout << "Constructor called" << std::endl;
}

Serializer::~Serializer(){
    std::cout << "Destructor called" << std::endl;
}

Serializer::Serializer(const Serializer &cpy){
    std::cout << "Constructor copy called" << std::endl;
    *this = cpy;
}

Serializer& Serializer::operator=(const Serializer &serializer){
    std::cout << "Assignement operator called" << std::endl;
    if (this != &serializer)
        *this = serializer;
    return (*this);
}

Data* Serializer::deserialize(uintptr_t raw){
    return (reinterpret_cast<Data*>(raw));
}

uintptr_t Serializer::serialize(Data *ptr){
    return (reinterpret_cast<uintptr_t>(ptr));
}
