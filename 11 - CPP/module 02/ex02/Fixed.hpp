/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 10:30:33 by thomas            #+#    #+#             */
/*   Updated: 2025/05/20 10:50:10 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <iomanip>

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

        static Fixed min(Fixed& Value1, Fixed& Value2);
        static Fixed min(const Fixed& value1, const Fixed& value2);
        static Fixed max(Fixed& value1, Fixed& value2);
        static Fixed max(const Fixed& value1, const Fixed& value2);
        
        bool    operator>(const Fixed &f) const;
        bool    operator<(const Fixed &f) const;
        bool    operator>=(const Fixed &f) const;
        bool    operator<=(const Fixed &f) const;
        bool    operator==(const Fixed &f) const;
        bool    operator!=(const Fixed &f) const;

        Fixed   operator+(const Fixed &f) const;
        Fixed   operator-(const Fixed &f) const;
        Fixed   operator*(const Fixed &f) const;
        Fixed   operator/(const Fixed &f) const;

        Fixed&    operator++();
        Fixed   operator++(int);
        Fixed&  operator--();
        Fixed   operator--(int);
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);
#endif