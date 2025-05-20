/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 10:30:05 by thomas            #+#    #+#             */
/*   Updated: 2025/05/20 10:57:03 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    

    Fixed test(3000000);
    std::cout << "Avant incrément : " << test << std::endl;
    test++;
    std::cout << "Après incrément : " << test << std::endl;

    std::cout << test << std::endl;
    std::cout << "valeure de a : " << a << std::endl;
    std::cout << "on pré-incrémente a :" << --a << std::endl;
    std::cout << "on affiche la nouvelle valeure de a: " << a << std::endl;
    std::cout << "on affiche d'abord la valeure actuel de a avant de l'incrémenter :" << a-- << std::endl;
    std::cout << "nouvelle valeure de a après incrémentation " << a << std::endl;
    std::cout << "on affiche la valeure de b: " << b << std::endl;
    std::cout << "on compare a et b et on renvoie le plus grand : " << Fixed::min( a, b ) << std::endl;
    return 0;
}