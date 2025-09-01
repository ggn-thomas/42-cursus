/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:13:36 by thgaugai          #+#    #+#             */
/*   Updated: 2025/09/01 12:37:40 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>
#include <cstdlib>

int main(){
    Span span[10];
    
    srand(time(NULL));
    for (int i = 0; i < 9; i++){
        span[i] = rand();
    }

    try {
        span->addNumber(15);
    }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    return 0;
}