/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:12:01 by thomas            #+#    #+#             */
/*   Updated: 2025/07/31 18:30:30 by thomas           ###   ########.fr       */
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
    if (name == "robotomy request")
        return new RobotomyRequestForm(target);
    else if (name == "shrubbery creation")
        return new ShrubberyCreationForm(target);
    else if (name == "president pardon")
        return new PresidentialPardonForm(target);
    else{
        std::cout << "No forms by that name : " << name << " has been found." << std::endl;
        return (NULL);
    }
}