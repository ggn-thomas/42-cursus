/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:50:37 by thomas            #+#    #+#             */
/*   Updated: 2025/08/05 14:37:14 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include <fstream>
# include <stdexcept>

class Bureaucrat{
    private:
        const std::string _name;
        int _grade;
        
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, const int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &cpy);
        Bureaucrat& operator=(const Bureaucrat &cpy);
        
        std::string getName() const;
        int         getGrade() const;
        void        incrementeGrade();
        void        decrementeGrade();

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
#endif