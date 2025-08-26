/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:03:39 by thomas            #+#    #+#             */
/*   Updated: 2025/08/26 11:39:30 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"


template<typename T>
void    swap(T& value1, T& value2){
    T   tmp;

    tmp = value1;
    value1 = value2;
    value2 = tmp;
}

template<typename T>
void    iter(T *tab, int len, void (*function)(T&, T&)){
    for (int i = 0; i < len - 1; i++)
        function(tab[i], tab[i+1]);
}

int main(){
    char tab[] = "TH";
    
    int tabInt[] = {1,99};

    iter(tabInt, 2, swap<int>);
    for (int i = 0; i < 2; i++)
        std::cout << tabInt[i] << ", ";
        

    iter(tab, 2, swap<char>);
    std::cout << std::endl << tab << std::endl;
}
