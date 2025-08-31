/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:03:39 by thomas            #+#    #+#             */
/*   Updated: 2025/08/27 14:55:17 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"


void    increment(int &value){
    value+=10;
}

void    toUpper(char &c){
    c = toupper(c);
}

int main(){
    char tab[] = "hello world";
    
    int tabInt[] = {1,99};

    iter(tabInt, 2, increment);
    for (int i = 0; i < 2; i++)
        std::cout << tabInt[i] << ", ";
        
    iter(tab, 12, toUpper);
    std::cout << std::endl << tab << std::endl;
}
