/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 10:30:33 by thomas            #+#    #+#             */
/*   Updated: 2025/05/14 10:55:52 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class   Fixed{
    private:
        int nb;
        static const int    nb_bits=8;

    public:
        Fixed();
        Fixed(const int value);
        Fixed (const float value);
        Fixed(const Fixed &copy);
        Fixed& operator=(const Fixed& fixed);
        ~Fixed();

        int getRawBits(void) const;
        void    setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;        
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);
#endif