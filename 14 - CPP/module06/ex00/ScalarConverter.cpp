/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:25:45 by thgaugai          #+#    #+#             */
/*   Updated: 2025/08/25 16:36:38 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : str("default") {
    std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(std::string str) : str(str) {
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
    if (this != &sc)
        *this = sc;
    return (*this);
}

void ScalarConverter::convert(std::string str) {
    int type;

    type = checkTypes(str);
    if (!type){
        std::cout << "Variable type is invalid !"  << std::endl;
        return ;
    }
    switch(type) {
        case INT:
            intConverter(str);
            break;
        case CHAR:
            charConverter(str);
            break;
        case DOUBLE:
            doubleConverter(str);
            break;
        case FLOAT:
            floatConverter(str);
            break;
        case PLITERAL:
            pliteralConverter(str);
            break;        
    }   
}
