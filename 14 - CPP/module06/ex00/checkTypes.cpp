/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkTypes.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:06:12 by thomas            #+#    #+#             */
/*   Updated: 2025/08/25 16:11:44 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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

int isFloat(std::string str, int dot){
    int i = 0;
    int len = str.length();
    
    if (str[(len - 1)] != 'f')
        return 0;
    while (i <= (len - 2)){
        if (i == dot)
            i++;
        if (!(isdigit(str[i])))
            return 0;
        i++;
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

int checkTypes(std::string str){
        
    size_t dot = str.find('.');
    size_t f = str.find('f');
    
    if (dot == std::string::npos) //si jamais la fonction find() ne trouve pas de point
    {
        if (isPliteral(str))
            return PLITERAL;
        if (isInt(str))
            return INT;
        if (isChar(str))
            return CHAR;
    }
    else if (f == std::string::npos){
        if (isDouble(str, dot))
            return DOUBLE;
    }
    else {
        if (isFloat(str, dot))
            return FLOAT;
    }
    return 0;
}