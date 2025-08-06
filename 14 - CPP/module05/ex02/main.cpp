/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:30:58 by thomas            #+#    #+#             */
/*   Updated: 2025/08/06 13:37:10 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Bureaucrat.hpp"

int main()
{
    Bureaucrat  patron("patron", 1);
    Bureaucrat  rh("rh", 10);
    Bureaucrat  salarier("salarier", 150);
    
    PresidentialPardonForm form1("president");
    RobotomyRequestForm form2("robotomy");
    ShrubberyCreationForm form3("shrubbery");

    std::cout << "================================ PATRON ================================" << std::endl << std::endl;
    patron.signForm(form1);
    patron.executeForm(form1);
    std::cout << "------------------------------------------------------------------------" << std::endl;
    patron.signForm(form2);
    patron.executeForm(form2);
    std::cout << "------------------------------------------------------------------------" << std::endl;
    patron.signForm(form3);
    patron.executeForm(form3);

    std::cout << "================================== RH ==================================" << std::endl << std::endl;
    rh.signForm(form1);
    rh.executeForm(form1);
    std::cout << "------------------------------------------------------------------------" << std::endl;
    rh.signForm(form2);
    rh.executeForm(form2);
    std::cout << "------------------------------------------------------------------------" << std::endl;
    rh.signForm(form3);
    rh.executeForm(form3);

    std::cout << "=============================== SALARIER  ==============================" << std::endl << std::endl;
    salarier.signForm(form1);
    salarier.executeForm(form1);
    std::cout << "------------------------------------------------------------------------" << std::endl;
    salarier.signForm(form2);
    salarier.executeForm(form2);
    std::cout << "------------------------------------------------------------------------" << std::endl;
    salarier.signForm(form3);
    salarier.executeForm(form3);
    
    std::cout << std::endl << "CLEAN" << std::endl;
    
    return 0;
}