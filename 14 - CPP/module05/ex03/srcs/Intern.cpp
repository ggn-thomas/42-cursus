/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:12:01 by thomas            #+#    #+#             */
/*   Updated: 2025/08/06 14:28:52 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern(){
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern(){
    std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern &cpy){
    std::cout << "Intern copy constructor called" << std::endl;
    (void)cpy;
}

Intern Intern::operator=(const Intern& intern){
    std::cout << "Intern assignement constructor called" << std::endl;
    (void)&intern;
    return (*this);
}

AForm *Intern::makeForm(std::string name, std::string target){
    AForm   *form;
    std::string tabForm[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
    int j = -1;
    
    for (int i = 0; i < 3 ; i++){
        if (name == tabForm[i])
            j = i; 
    }

    switch(j) {
        case 0:
            std::cout << "Intern creates " << name << " form" << std::endl;
            form = new RobotomyRequestForm(target);
            break;
        case 1:
            std::cout << "Intern creates " << name << " form" << std::endl;
            form = new PresidentialPardonForm(target);
            break;
        case 2:
            std::cout << "Intern creates " << name << " form" << std::endl;
            form = new ShrubberyCreationForm(target);
            break;
        case -1:
            std::cerr << "Error: " << name << " form doesn't exist !" << std::endl;
            form = 0;
    }
    return form;
}