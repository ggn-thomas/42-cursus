/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 09:53:39 by thomas            #+#    #+#             */
/*   Updated: 2025/08/26 11:04:15 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

template<typename T>
void    swap(T& value1, T& value2){
    T   tmp;

    tmp = value1;
    value1 = value2;
    value2 = tmp;
}

template<typename T>
T&  min(T& value1, T& value2){
    if (value1 == value2)
        return value2;
    else if (value1 > value2)
        return value2;
    else
        return value1;
}

template<typename T>
T&  max(T& value1, T& value2){
    if (value1 == value2)
        return value2;
    else if (value1 < value2)
        return value2;
    else
        return value1;
}

int main( void ) {
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;
}