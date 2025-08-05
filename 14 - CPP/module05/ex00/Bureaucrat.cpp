/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:02:07 by thomas            #+#    #+#             */
/*   Updated: 2025/08/05 14:56:40 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150){
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade) : _name(name), _grade(grade) {
    std::cout << "Bureaucrat parameterized constructor called" << std::endl;
    if (this->_grade > 150)
        throw (GradeTooLowException());
    else if (this->_grade < 1)
        throw (GradeTooHighException());
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
        throw(GradeTooLowException());
}

void    Bureaucrat::incrementeGrade(){
    this->_grade--;
    if (this->_grade < 1)
       throw (GradeTooHighException());
}

std::string Bureaucrat::getName() const{
    return (this->_name);
}

int Bureaucrat::getGrade() const{
    return (this->_grade);
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat){
    os << bureaucrat.getName() << " , bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
    return os;
}
