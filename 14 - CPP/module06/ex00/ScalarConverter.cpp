/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:25:45 by thgaugai          #+#    #+#             */
/*   Updated: 2025/08/25 13:51:52 by thomas           ###   ########.fr       */
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

int isInt(std::string str){
    int i = 0;

    if (str[0] == '-' || str[0] == '+')
    {
        if (str.length() > 11)
            return 0;
        i++;
    }
    else {
        if (str.length() > 10)
            return 0;
    }
    while (str[i])
    {
        if (!isdigit(str[i++]))
            return 0;
    }
    return 1;
}

int isChar(std::string str){
    int i = 0;

    while(str[i]){
        if (!(isalpha(str[i++])))
            return 0;
    }
    return 1;
}

int isFloat(std::string str, int dot, int l){
    int i = 0;

    if (str[(str.length() - 1)] != 'f')
        return 0;
    while (i <= (str.length() - 1)){
        if (i == dot)
            i++;
        if (!(isdigit(str[i])))
            return 0;
    }
    return 1;
}

int isPliteral(std::string str){
    if (str == "-inff" || str == "+inff" || str == "nanf" || str == "-inf" || str == "+inf" || str == "nan")
        return 1;
    else
        return 0;
}

int isDouble(std::string str, int dot){
    int i = 0;

    while (str[i]){
        if (i == dot)
            i++;
        if (!(isdigit(str[i])))
            return 0;
    }
    return 1;
}

void ScalarConverter::convert(std::string str) {
    
    size_t dot = str.find('.');
    size_t f = str.find('f');
    
    if (dot == std::string::npos) //si jamais la fonction find() ne trouve pas de point
    {
        if (isInt(str))
            return 
        if (isChar(str, len))
            return
        if (isPliteral(str))
            return 
    }
    else if (f == std::string::npos)
        if (isDouble(str, dot))
            return 
     isFloat(str, dot, f)
        return
}
