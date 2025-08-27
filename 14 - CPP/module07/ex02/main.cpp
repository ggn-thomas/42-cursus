/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:45:04 by thomas            #+#    #+#             */
/*   Updated: 2025/08/27 14:15:56 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(){
    Array<int> arr(5);
    Array<char> arr1(10);

    std::cout << "Array length: " <<  arr1.size() << std::endl;
    try{
        std::cout << arr1[7] << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    try{
        std::cout << arr1[9] << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    std::cout << "Array length: " <<  arr.size() << std::endl;
    try{
        std::cout << arr[4] << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
}