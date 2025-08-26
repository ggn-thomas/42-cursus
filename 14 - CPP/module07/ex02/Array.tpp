/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:18:29 by thomas            #+#    #+#             */
/*   Updated: 2025/08/26 13:18:32 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

// constructor
template<typename T>
Array<T>::Array() : _array(NULL), _size(0){
}

template<typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n){
}

template<typename T>
Array<T>::Array(const Array &cpy) : _array(new T[cpy._size], _size(cpy._size)) {
    for (size_t i = 0; i < this->_size; i++){
        this->_array[i] = cpy._array[i];
    }
}

// operator
template<typename T>
Array<T> &Array<T>::operator=(Array const &cpy){
    delete _array;

    if (this != &cpy){
        this->_size = cpy._size;
        this->_array = new T[cpy._size];
        for (size_t i = 0; i < _size ; i++){
            this->_array[i] = cpy._array[i]
        }
    }
    return *this;
}

template<typename T>
T &Array<T>::operator[](unsigned int n){
    
}

// destructor
template<typename T>
Array<T>::~Array(){
    delete _array;
}




#endif
