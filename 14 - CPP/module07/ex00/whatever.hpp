/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 09:53:57 by thomas            #+#    #+#             */
/*   Updated: 2025/08/30 17:04:14 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
template<typename T>
void    swap(T& value1, T& value2){
    T   tmp;

    tmp = value1;
    value1 = value2;
    value2 = tmp;
}

template<typename T>
T&  min(T& value1, T& value2){
    if (value1 == value2)
        return value2;
    else if (value1 > value2)
        return value2;
    else
        return value1;
}

template<typename T>
T&  max(T& value1, T& value2){
    if (value1 == value2)
        return value2;
    else if (value1 < value2)
        return value2;
    else
        return value1;
}
#endif