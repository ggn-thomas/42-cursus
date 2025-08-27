/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:41:46 by thomas            #+#    #+#             */
/*   Updated: 2025/08/27 14:12:26 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class Array {
    private:
        T               *_array;
        size_t          _size;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array &cpy);
        Array& operator=(const Array &cpy);
        T& operator[](unsigned int n);
        ~Array();
    
    size_t size () const ;
    class BadIndex : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    

};

#include "Array.tpp"
#endif