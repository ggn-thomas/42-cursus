/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:25:45 by thgaugai          #+#    #+#             */
/*   Updated: 2025/08/06 15:38:40 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : str("default") {
    std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter(){
    std::cout << "Default destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy){
    std::cout << "Copy constructor called" << std::endl;
    if (this != &cpy)
        this->str = cpy.str;
}

ScalarConverter ScalarConverter::operator=(const ScalarConverter &sc){
    std::cout << "Copy assignement constructor called" << std::endl;
}

