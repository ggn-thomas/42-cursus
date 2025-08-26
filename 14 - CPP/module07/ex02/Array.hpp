/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:41:46 by thomas            #+#    #+#             */
/*   Updated: 2025/08/26 13:17:04 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class Array {
    private:
        T               *_array;
        size_t          size;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array &cpy);
        Array& operator=(const Array &cpy);
        Array& operator[](unsigned int n);
        Array& operator[](unsigned int n) const;
        ~Array();

    
    int size();
    
};

#include "Array.tpp"
#endif