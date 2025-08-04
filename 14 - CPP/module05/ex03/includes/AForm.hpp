/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:11:31 by thomas            #+#    #+#             */
/*   Updated: 2025/07/31 17:07:13 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

# include <iostream>

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool    _isSigned;
        const int   _gradeExecute;
        const int   _gradeSign;
        
    public:
        AForm();
        AForm (const std::string name, const int gradeExecute, const int gradeSign);
        virtual ~AForm();
        AForm(const AForm &cpy);
        AForm &operator=(const AForm &form);

        virtual std::string getName() const;
        bool    getIsSigned() const;
        int     getGradeExecute() const;
        int     getGradeSign() const;
        void    beSigned(const Bureaucrat& bureaucrat);
        void    execute(Bureaucrat const &executor) const;
        virtual void executeAction() const = 0;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw(){
                    return ("Grade too low");
                }
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return ("Grade too high");
                }
        };

        class FormNotSignedException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return ("Forms needs to be signed before executing");
                }
        };
};

std::ostream &operator<<(std::ostream& os, const AForm& form);

#endif