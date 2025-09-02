/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:13:36 by thgaugai          #+#    #+#             */
/*   Updated: 2025/09/02 17:09:13 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>
#include <cstdlib>

// int main(){
//     Span span(10000);
//     Span SpanCrash(10000);

//     try {
//         span.addNumber(15);
//         span.addNumber(1);
//         span.addNumber(5);
//         span.addNumber(8);
//         span.addNumber(155);
//     }
//     catch (std::exception &e){
//         std::cerr << e.what() << std::endl;
//     }

//     try {
//         int longS = span.longestSpan();
//         int shortS = span.shortestSpan();

//         std::cout << "short span: " << shortS << " | " << "long span: " << longS << std::endl;
//     }
//     catch (std::exception &e){
//         std::cerr << e.what() << std::endl;
//     }


//     try {
//         // SpanCrash.addNumber(5);
//         int longS = SpanCrash.longestSpan();
//         int shortS = SpanCrash.shortestSpan();

//         std::cout << "short span: " << shortS << " | " << "long span: " << longS << std::endl;
//     }
//     catch (std::exception &e){
//         std::cerr << e.what() << std::endl;
//     }
    
//     return 0;
// }

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}
