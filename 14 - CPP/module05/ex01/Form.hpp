/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:11:31 by thomas            #+#    #+#             */
/*   Updated: 2025/08/05 15:00:27 by thgaugai         ###   ########.fr       */
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
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw() ;
        }; 
};

std::ostream &operator<<(std::ostream& os, const Form& form);

#endif