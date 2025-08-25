/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:45:03 by thomas            #+#    #+#             */
/*   Updated: 2025/08/25 15:53:49 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av){
    
    if (ac != 2){
        std::cout << "Please enter value!" << std::endl;
        return 0;
    }
    ScalarConverter::convert(av[1]);

    return 0;
}