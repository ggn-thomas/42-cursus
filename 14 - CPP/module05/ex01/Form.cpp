/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:11:21 by thomas            #+#    #+#             */
/*   Updated: 2025/08/06 13:52:53 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form () : _name("default"), _isSigned(false), _gradeExecute(150), _gradeSign(150){
    std::cout << "Default Form constructor called" << std::endl;
}

Form::Form (const std::string name, const int gradeExecute, const int gradeSign) : _name(name), _isSigned(false), _gradeExecute(gradeExecute), _gradeSign(gradeSign){
    std::cout << "Form personnalized constructor called" << std::endl;
    if (gradeExecute > 150 || gradeSign > 150)
        (throw GradeTooLowException());
    else if (gradeExecute < 1 || gradeSign < 1)
        (throw GradeTooHighException());
}

Form::~Form(){
    std::cout << "Form destructor called" << std::endl;
}

Form::Form(const Form &cpy) : _name(cpy._name), _isSigned(cpy._isSigned), _gradeExecute(cpy._gradeExecute), _gradeSign(cpy._gradeSign){
    std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form &form){
    std::cout << "Form copy assignement operator called" << std::endl;
    (void)form;
    return (*this);
}

//getter
std::string Form::getName() const{
    return (this->_name);
}

int Form::getGradeExecute() const{
    return (this->_gradeExecute);
}

int Form::getGradeSign() const{
    return (this->_gradeSign);
}

bool Form::getIsSigned() const{
    return (this->_isSigned);
}


const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too High";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Form &form){
    os << "Form " << form.getName() << ", signed: " << (form.getIsSigned() ? "yes" : "no") 
       << ", grade to sign: " << form.getGradeSign() 
       << ", grade to execute: " << form.getGradeExecute();
    return os;
}

void    Form::beSigned(const Bureaucrat& bureaucrat){
    if (this->_gradeSign < bureaucrat.getGrade())
        throw std::invalid_argument("Grade is insufficient to be signed!");
    else
        this->_isSigned = true;
}