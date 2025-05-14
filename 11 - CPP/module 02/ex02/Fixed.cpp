/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 10:30:29 by thomas            #+#    #+#             */
/*   Updated: 2025/05/14 13:09:05 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): nb(0){
}

Fixed::Fixed(const int value){
	this->nb = value << this->nb_bits;
}

Fixed::Fixed(const float value){
	this->nb = roundf(value * (1 << this->nb_bits));
}

Fixed::Fixed(const Fixed &copy){
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &fixed){
	if (this != &fixed) {
		this->nb = fixed.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed(){
}

int	Fixed::getRawBits(void) const{
	return (this->nb);
}

void	Fixed::setRawBits(int const raw){
	this->nb = raw;
	return ;
}

float	Fixed::toFloat(void) const {
	return ((float)this->nb / (float)(1 << this->nb_bits));
}

int	Fixed::toInt(void)const {
	return (this->nb >> this->nb_bits);
}

//opérateur de comparaison
bool	Fixed::operator>(const Fixed &f) const {
	return (this->toFloat() > f.toFloat());
}

bool	Fixed::operator<(const Fixed &f) const {
	return (this->toFloat() > f.toFloat());
}

bool	Fixed::operator>=(const Fixed &f) const {
	return (this->toFloat() >= f.toFloat());
}

bool	Fixed::operator<=(const Fixed &f) const {
	return (this->toFloat() <= f.toFloat());
}

bool	Fixed::operator==(const Fixed &f) const {
	return (this->toFloat() == f.toFloat());
}

bool	Fixed::operator!=(const Fixed &f) const {
	return (this->toFloat() != f.toFloat());
}

//opérateurs arithmétiques
Fixed	Fixed::operator+(const Fixed &f) const {
	return (this->toFloat() + f.toFloat());
}

Fixed	Fixed::operator-(const Fixed &f) const {
	return (this->toFloat() - f.toFloat());
}

Fixed	Fixed::operator*(const Fixed &f) const {
	return (this->toFloat() * f.toFloat());
}

Fixed	Fixed::operator/(const Fixed &f) const {
	return (this->toFloat() / f.toFloat());
}

//opérateurs d'incrémentation et de décrémentation
Fixed	&Fixed::operator++() {
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	temp = *this;
	this->setRawBits(this->getRawBits() + 1);
	return temp;
}

Fixed	&Fixed::operator--() {
	this->setRawBits(this->getRawBits() - 1);
	return *this;	
}

Fixed	Fixed::operator--(int) {
	Fixed	temp = *this;
	this->setRawBits(this->getRawBits() - 1);
	return temp;
}

Fixed	Fixed::min(Fixed& value1, Fixed& value2) {
	if (value1 > value2)
		return value2;
	else
		return value1;
}

Fixed	Fixed::min(const Fixed& value1, const Fixed& value2) {
	if (value1 > value2)
		return value2;
	else
		return value1;
}

Fixed	Fixed::max(Fixed& value1, Fixed& value2) {
	if (value1 > value2)
		return value1;
	else
		return value2;
}

Fixed	Fixed::max(const Fixed& value1, const Fixed& value2) {
	if (value1 > value2)
		return value1;
	else
		return value2;
}

std::ostream& operator<<(std::ostream& o, const Fixed& fixed){
	o << fixed.toFloat();
	return (o);
}