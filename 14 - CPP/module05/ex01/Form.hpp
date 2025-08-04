/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:11:31 by thomas            #+#    #+#             */
/*   Updated: 2025/07/31 17:24:40 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

# include <iostream>

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool    _isSigned;
        const int   _gradeExecute;
        const int   _gradeSign;
        
    public:
        Form();
        Form (const std::string name, const int gradeExecute, const int gradeSign);
        ~Form();
        Form(const Form &cpy);
        Form &operator=(const Form &form);

        std::string getName() const;
        bool    getIsSigned() const;
        int     getGradeExecute() const;
        int     getGradeSign() const;
        void    beSigned(const Bureaucrat& bureaucrat);

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw(){
                    return ("The grade you set is too high");
                }
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return ("The grade you set is too low");
                }
        }; 
};

std::ostream &operator<<(std::ostream& os, const Form& form);

#endif