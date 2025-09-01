/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:55:06 by thgaugai          #+#    #+#             */
/*   Updated: 2025/09/01 12:33:51 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iostream>

class Span {
    private:
        unsigned int _n;
        std::vector<int> _vec;

    public:
        Span();
        Span(unsigned int N);
        ~Span();
        Span(const Span& cpy);
        Span operator=(const Span& cpy);
    
        void    addNumber(int n);
        
    class SpanAlreadyFull : public std::exception {
        public:
            const char* what() const throw ();
    };
};
#endif