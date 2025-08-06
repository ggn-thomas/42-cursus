/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:11:21 by thomas            #+#    #+#             */
/*   Updated: 2025/08/06 13:31:41 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

AForm::AForm () : _name("default"), _isSigned(false), _gradeExecute(150), _gradeSign(150){
    std::cout << "Default Form constructor called" << std::endl;
}

AForm::AForm (const std::string name, const int gradeExecute, const int gradeSign) : _name(name), _isSigned(false), _gradeExecute(gradeExecute), _gradeSign(gradeSign){
    std::cout << "Form personnalized constructor called" << std::endl;
}

AForm::~AForm(){
    std::cout << "Form destructor called" << std::endl;
}

AForm::AForm(const AForm &cpy) : _name(cpy._name), _isSigned(cpy._isSigned), _gradeExecute(cpy._gradeExecute), _gradeSign(cpy._gradeSign){
    std::cout << "Form copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm &form){
    std::cout << "Form copy assignement operator called" << std::endl;
    (void)form;
    return (*this);
}

// getter
std::string AForm::getName() const{
    return (this->_name);
}

int AForm::getGradeExecute() const{
    return (this->_gradeExecute);
}

int AForm::getGradeSign() const{
    return (this->_gradeSign);
}

bool AForm::getIsSigned() const{
    return (this->_isSigned);
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too High";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw(){
    return "Forms needs to be signed before executing";
}

std::ostream& operator<<(std::ostream& os, const AForm &form){
    os << "Form " << form.getName() << ", signed: " << (form.getIsSigned() ? "yes" : "no") 
       << ", grade to sign: " << form.getGradeSign() 
       << ", grade to execute: " << form.getGradeExecute();
    return os;
}

void    AForm::beSigned(const Bureaucrat& bureaucrat){
    if (this->_gradeSign < bureaucrat.getGrade())
        throw std::invalid_argument("Grade is insufficient to be signed!");
    else
        this->_isSigned = true;
}

void    AForm::execute(Bureaucrat const &executor) const {
    if (!this->_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > this->getGradeExecute())
        throw GradeTooLowException();
    executeAction();
}
