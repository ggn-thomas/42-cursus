/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 10:30:29 by thomas            #+#    #+#             */
/*   Updated: 2025/05/12 17:39:22 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): nb(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	value << 8;
}

Fixed::Fixed(const float value)
{
	value * (2^8);
}

Fixed::Fixed(const Fixed& f){
	std::cout << "Copy constructor called" << std::endl;
	this->nb = f.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &f){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &f) {
		this->nb = f.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->nb);
}

void	Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called" << std::endl;
	this->nb = raw;
	return ;
}
