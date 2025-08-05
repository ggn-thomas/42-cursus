/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:30:58 by thomas            #+#    #+#             */
/*   Updated: 2025/08/05 17:01:01 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int main()
{
    try {
        Form testament("mamie", 5, 15);
        Bureaucrat  Thomas("Gaugain", 0);
        Thomas.signForm(testament);
    }
    catch (const std::exception &e){
        std::cout << "Error : " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << "==============================================================================" << std::endl << std::endl;
    try {
        Form contrat("contrat", 5, 15);
        Bureaucrat secretaire("eric", 25);

        secretaire.signForm(contrat);
    }
    catch (const std::exception &e){
        std::cout << "Error: " << e.what() << std::endl;
    }

        std::cout << std::endl;
    std::cout << "==============================================================================" << std::endl << std::endl;

    try {
        Form fakecontrat("fake", -1, 200);
        
    }
    catch (const std::exception &e){
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}