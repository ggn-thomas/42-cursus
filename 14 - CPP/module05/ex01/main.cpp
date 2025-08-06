/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:30:58 by thomas            #+#    #+#             */
/*   Updated: 2025/08/06 13:55:51 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int main()
{
    std::cout << "================================ BAD FORM ================================" << std::endl << std::endl;
    try {
        Form badForm("badForm", 1000, 1000);
    }
    catch (std::exception &e){
        std::cout << "Error : " << e.what() << std::endl;
    }

    try {
        Form badForm1("badForm", 0, 0);
    }
    catch (std::exception &e){
        std::cout << "Error : " << e.what() << std::endl;
    }
    
    std::cout << "================================ FORM ================================" << std::endl << std::endl;
    
    try {
    Form facture("facture", 5, 5);
    Form constat("constat", 120 , 150);
    
    Bureaucrat  patron("Boss", 1);
    Bureaucrat  secretaire("secretaire", 122);

    std::cout << facture << std::endl;
    std::cout << constat << std::endl;
    
    patron.signForm(facture);
    secretaire.signForm(facture);

    patron.signForm(constat);
    secretaire.signForm(constat);

    std::cout << facture << std::endl;
    std::cout << constat << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}