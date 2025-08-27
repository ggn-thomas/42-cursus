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


void    incremente(int &value){
    value+=10;
}

void    toUPPER(char &c){
    c = toupper(c);
}

template<typename T_tab, typename T_function>
void    iter(T_tab *tab, size_t len, T_function function) {
    for (size_t i = 0; i < len - 1; i++)
        function(tab[i]);
}

int main(){
    char tab[] = "hello world";
    
    int tabInt[] = {1,99};

    iter(tabInt, 2, incremente);
    for (int i = 0; i < 2; i++)
        std::cout << tabInt[i] << ", ";
        
    iter(tab, 12, toUPPER);
    std::cout << std::endl << tab << std::endl;
}
