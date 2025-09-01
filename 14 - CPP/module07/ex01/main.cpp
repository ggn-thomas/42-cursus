/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:03:39 by thomas            #+#    #+#             */
/*   Updated: 2025/09/01 14:33:08 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void    increment(int &value){
    value+=10;
}

void    toUpper(char &c){
    c = toupper(c);
}


void    print(const char &c){
    std::cout << c ;
}

int main(){
    char tab[] = "hello world";
    char const tabConst[] = "hi 42";
    
    int tabInt[] = {1,99};

    iter(tabInt, 2, increment);
    for (int i = 0; i < 2; i++)
        std::cout << tabInt[i] << ", ";
        
    iter(tab, 12, toUpper);
    std::cout << std::endl << tab << std::endl;

    iter(tabConst, 5, print);
}
