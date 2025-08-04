/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:02:07 by thomas            #+#    #+#             */
/*   Updated: 2025/07/31 17:31:27 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150){
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade) : _name(name), _grade(grade) {
    std::cout << "Bureaucrat parameterized constructor called" << std::endl;
    if (this->_grade > 150)
        throw (Bureaucrat::GradeTooLowException());
    else if (this->_grade < 1)
        throw (Bureaucrat::GradeTooHighException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) : _name(cpy._name), _grade(cpy._grade) {
    std::cout << "Bureaucrat default copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &cpy){
    std::cout << "Default assignment operator called" << std::endl;
    if (this != &cpy)
        this->_grade = cpy._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat destructor called" << std::endl;
}

void    Bureaucrat::decrementeGrade(){
    this->_grade++;
    if (this->_grade > 150)
        Bureaucrat::GradeTooLowException();
}

void    Bureaucrat::incrementeGrade(){
    this->_grade--;
    if (this->_grade < 1)
        Bureaucrat::GradeTooHighException();
}

std::string Bureaucrat::getName() const{
    return (this->_name);
}

int Bureaucrat::getGrade() const{
    return (this->_grade);
}

void    Bureaucrat::signForm(Form &form){
    try {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e){
        std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat){
    os << bureaucrat.getName() << " , bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
    return os;
}
