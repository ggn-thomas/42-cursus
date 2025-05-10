/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 10:30:33 by thomas            #+#    #+#             */
/*   Updated: 2025/05/10 10:53:27 by thomas           ###   ########.fr       */
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
        Fixed(const Window& );
        Fixed& operator=(const Fixed& f);
        ~Fixed();
        
        int getRawBits(void) const;
        void    setRawBits(int const raw);
};
#endif