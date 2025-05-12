/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 10:30:33 by thomas            #+#    #+#             */
/*   Updated: 2025/05/10 17:22:32 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class   Fixed{
    private:
        int nb;
        static const int    nb_bits=8;

    public:
        Fixed();
        Fixed(const int value);
        Fixed (const float value);
        Fixed(const Fixed& );
        Fixed& operator=(const Fixed&);
        ~Fixed();

        int getRawBits(void) const;
        void    setRawBits(int const raw);
};
#endif