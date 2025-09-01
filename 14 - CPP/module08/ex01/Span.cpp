/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:09:17 by thgaugai          #+#    #+#             */
/*   Updated: 2025/09/01 12:41:05 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0) {   
}

Span::Span(unsigned int N) : _n(N){
}

Span::~Span(){
}

Span::Span(const Span &cpy) : _n(cpy._n){
}

Span Span::operator=(const Span &cpy) {
    if (this != &cpy)
        this->_n = cpy._n;
    return *this;
}

const char* Span::SpanAlreadyFull::what() const throw (){
    return "Span is already full!";
}

void Span::addNumber(int n){
    if (!(std::is_empty)(_vec[_n - 1]))
        _vec[_n -1] = n;
    else
        throw (SpanAlreadyFull()); 
}

