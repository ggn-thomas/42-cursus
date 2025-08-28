/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:18:49 by thomas            #+#    #+#             */
/*   Updated: 2025/08/27 14:09:06 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void pliteralConverter(std::string str){
    if (str == "nan" || str == "nanf"){
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (str == "+inf" || str == "+inff"){
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (str == "-inf" || str == "-inff"){
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

void charConverter(std::string str){
    char c = str[0];
    
    std::cout << "char: ";
    if (isprint(c)){
        std::cout << c << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;   
        std::cout << "float: " << static_cast<float>(c) << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
    }
    else
        std::cout << "Non displayable" << std::endl;
}

void intConverter(std::string str){
    long val = atol(str.c_str());
    
    std::cout << "char: " ;
    if (val < 0 || val > 127)
        std::cout << "impossible" << std::endl;
    else {
        if (isprint(val))
            std::cout << static_cast<char>(val) << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    }
    std::cout << "int: ";
    if (val < INT_MIN || val > INT_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(val) << std::endl;
    std::cout << "float: " << static_cast<float>(val) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(val) <<  ".0" << std::endl;   
}

void floatConverter(std::string str){
    float val = atof(str.c_str());
    size_t flag = str.find(".0f");
    
    std::cout << "char: ";
    if (val < 0 || val > 127)
        std::cout << "impossible" << std::endl;
    else {
        if (isprint(val))
            std::cout << static_cast<char>(val) << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    }
    std::cout << "int: ";
    if (static_cast<int>(val) > INT_MAX || static_cast<int>(val) < INT_MIN)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(val) << std::endl;
    std::cout << "float: ";
    if (val > FLT_MAX || val < FLT_MIN)
        std::cout << "impossible" << std::endl;
    else {
        if (flag != std::string::npos)
            std::cout << val << ".0f" << std::endl;
        else
            std::cout << val << "f" << std::endl;
    }
    std::cout << "double: " ;
    if (flag != std::string::npos)
        std::cout << static_cast<double>(val) << ".0" << std::endl;
    else
        std::cout << static_cast<double>(val) << std::endl;
}

void    doubleConverter(std::string str){
    double val = atof(str.c_str());
    size_t flag = str.find(".0");

    std::cout << "char: ";
    if (val < 0 || val > 127)
        std::cout << "impossible" << std::endl;
    else {
        if (isprint(val))
            std::cout << static_cast<char>(val) << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    }
    std::cout << "int: ";
    if (val > INT_MAX || val < INT_MIN)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(val) << std::endl;
    std::cout << "float: ";
    if (val > FLT_MAX || val < FLT_MIN)
        std::cout << "impossible" << std::endl;
    else {
        if (flag != std::string::npos)
            std::cout << val << ".0f" << std::endl;
        else
            std::cout << val << "f" << std::endl;
    }
    std::cout << "double: ";
	if (val < MIN_DOUBLE || val > MAX_DOUBLE)
		std::cout << "impossible" << std::endl;
    else {
        if (flag != std::string::npos)
            std::cout << static_cast<double>(val) << ".0" << std::endl;
        else
            std::cout << static_cast<double>(val) << std::endl;
    }
}