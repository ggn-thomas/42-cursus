/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:24:28 by thgaugai          #+#    #+#             */
/*   Updated: 2025/08/27 11:00:40 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cctype>
#include <string>
#include <cfloat>
#include <climits>
#include <limits>
#include <cstdlib>

#define INT 1
#define CHAR 2
#define DOUBLE 3
#define FLOAT 4
#define PLITERAL 5
#define MIN_DOUBLE -DBL_MAX
#define MAX_DOUBLE DBL_MAX

class ScalarConverter {
    private:
        std::string str;
        ScalarConverter();
        ScalarConverter(std::string str);
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &cpy);
        
    public:
        ScalarConverter operator=(const ScalarConverter &sc);

    static void convert(std::string str);
};

int     checkTypes(std::string str);
void    doubleConverter(std::string str);
void    floatConverter(std::string str);
void    intConverter(std::string str);
void    charConverter(std::string str);
void    pliteralConverter(std::string str);

#endif