/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:44:35 by thomas            #+#    #+#             */
/*   Updated: 2025/07/31 17:59:26 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 45, 72), target("default") {
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 45, 72), target(target){
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) : AForm (cpy), target(cpy.target){
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &robotomyRequestForm){
    std::cout << "RobotomyRequestForm assignement operator constructor called" << std::endl;
    if (this != &robotomyRequestForm)
        this->target != robotomyRequestForm.target;
    return *this;
}

void RobotomyRequestForm::executeAction() const {
    std::cout << "BZZZZT! DRILL NOISES!" << std::endl;
    
    if (rand() % 2) {
        std::cout << this->target << " has been robotomized succesfully" << std::endl;
    } else {
        std::cout << "Robotomy failed" << std::endl;
    }
}