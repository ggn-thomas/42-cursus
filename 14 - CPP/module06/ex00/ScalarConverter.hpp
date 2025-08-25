/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:24:28 by thgaugai          #+#    #+#             */
/*   Updated: 2025/08/25 13:51:20 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cctype>
#include <string>
#include <cfloat>

#define INT 1
#define CHAR 2
#define DOUBLE 3
#define FLOAT 4
#define PLITERAL 5

class ScalarConverter {
    private:
        std::string str;
        
    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &cpy);
        ScalarConverter operator=(const ScalarConverter &sc);

    static void convert(std::string str);
};

#endif