/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:18:29 by thomas            #+#    #+#             */
/*   Updated: 2025/08/27 15:02:14 by thgaugai         ###   ########.fr       */
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
Array<T>::Array(const Array &cpy) : _array(new T[cpy._size]), _size(cpy._size) {
    for (unsigned int i = 0; i < this->_size; i++){
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
            this->_array[i] = cpy._array[i];
        }
    }
    return *this;
}

template<typename T>
T &Array<T>::operator[](unsigned int n) const{
    if (n >= _size)
        throw (BadIndex());
    else
        return _array[n];
}

template<typename T>
T &Array<T>::operator[](unsigned int n){
    if (n >= _size)
        throw (BadIndex());
    else
        return _array[n];
}

// destructor
template<typename T>
Array<T>::~Array(){
    delete _array;
}

//exception
template<typename T>
const char* Array<T>::BadIndex::what() const throw(){
    return "This index is outside the array!";
}

template<typename T>
size_t Array<T>::size() const {
    return (this->_size);
}

#endif
