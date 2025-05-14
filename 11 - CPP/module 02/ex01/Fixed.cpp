/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 10:30:29 by thomas            #+#    #+#             */
/*   Updated: 2025/05/14 13:11:58 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): nb(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value){
	std::cout << "Int constructor called" << std::endl;
	this->nb = value << this->nb_bits;
}

Fixed::Fixed(const float value){
	std::cout << "Float constructor called" << std::endl;
	this->nb = roundf(value * (1 << this->nb_bits));
}

Fixed::Fixed(const Fixed &copy){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &fixed){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed) {
		this->nb = fixed.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const{
	return (this->nb);
}

void	Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called" << std::endl;
	this->nb = raw;
	return ;
}

float	Fixed::toFloat(void) const {
	return ((float)this->nb / (float)(1 << this->nb_bits));
}

int	Fixed::toInt(void)const {
	return (this->nb >> this->nb_bits);
}

std::ostream& operator<<(std::ostream& o, const Fixed& fixed){
	o << fixed.toFloat();
	return (o);
}

