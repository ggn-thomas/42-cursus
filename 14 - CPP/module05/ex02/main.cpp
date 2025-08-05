/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:30:58 by thomas            #+#    #+#             */
/*   Updated: 2025/08/05 18:04:58 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Bureaucrat.hpp"

int main()
{
    Bureaucrat  Thomas("Gaugain", 30);
    PresidentialPardonForm home("home");

    Thomas.signForm(home);
    home.execute(Thomas);

    std::cout << std::endl;
    std::cout << "==============================================================================" << std::endl << std::endl;
    
    Bureaucrat  Thomas("Gaugain", 20);
    PresidentialPardonForm home("home");

    Thomas.signForm(home);
    home.execute(Thomas);

    std::cout << std::endl;
    std::cout << "==============================================================================" << std::endl << std::endl;

    Bureaucrat  Thomas("Gaugain", 2);
    PresidentialPardonForm home("home");
    Thomas.signForm(home);

    
    home.execute(Thomas);
}