/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:09:17 by thgaugai          #+#    #+#             */
/*   Updated: 2025/09/01 17:45:00 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _limits(0) {   
}

Span::Span(unsigned int N) : _limits(N){
}

Span::~Span(){
}

Span::Span(const Span &cpy) : _limits(cpy._limits){
}

Span Span::operator=(const Span &cpy) {
    if (this != &cpy)
        this->_limits = cpy._limits;
    return *this;
}

const char* Span::LimitsExceed::what() const throw (){
    return "Limits exceeded!";
}

const char* Span::InsufficientNumbers::what() const throw() {
    return "Insufficients numbers!";
}

int Span::shortestSpan(){
    int span = INT_MAX;
    int tmp = 0;
    
    if (_numbers.size() <= 2)
        throw (InsufficientNumbers());
    std::sort(_numbers.begin(), _numbers.end());

    for (unsigned long i = 0; (i < _numbers.size() - 1) ; i++){
        tmp = _numbers[i + 1] - _numbers[i];
        if (tmp < span)
           span = tmp;
    }
    return span;
}

int Span::longestSpan(){
    int span = -2147483648;
    int tmp = 0;
    
    if (_numbers.size() <= 2)
        throw (InsufficientNumbers());
    std::sort(_numbers.begin(), _numbers.end());

    for (unsigned long i = 0; (i < _numbers.size() - 1) ; i++){
        tmp = _numbers[i + 1] - _numbers[i];
        if (tmp > span)
           span = tmp;
    }
    return span;
}

void Span::addNumber(unsigned int n){
    if (n >= _limits)
        throw (LimitsExceed());
    else
        _numbers.push_back(n);
}

