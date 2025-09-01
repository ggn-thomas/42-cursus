/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:55:06 by thgaugai          #+#    #+#             */
/*   Updated: 2025/09/01 17:19:06 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>

#define INT_MAX 2147483647

class Span {
    private:
        unsigned int _limits;
        std::vector<int> _numbers;

    public:
        Span();
        Span(unsigned int N);
        ~Span();
        Span(const Span& cpy);
        Span operator=(const Span& cpy);
    
        void    addNumber(unsigned int n);
        int     shortestSpan();
        int     longestSpan();
        
    class LimitsExceed : public std::exception {
        public:
            const char* what() const throw ();
    };
    
    class  InsufficientNumbers : public std::exception {
        public:
            const char* what() const throw();
    };
};
#endif