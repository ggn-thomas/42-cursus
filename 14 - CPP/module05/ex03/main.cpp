/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:30:58 by thomas            #+#    #+#             */
/*   Updated: 2025/08/06 14:35:55 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Intern.hpp"

int main()
{
    Intern  thomas;
    
    std::cout << std::endl << "================================ BADFORM ================================" << std::endl << std::endl;
    AForm *form1 = thomas.makeForm("badform123", "badform");

    std::cout << std::endl << "================================ CORRECTFORM ================================" << std::endl << std::endl;
    AForm *form2 = thomas.makeForm("robotomy request", "test1");
    std::cout << std::endl;
    AForm *form3 = thomas.makeForm("presidential pardon", "test2");
    std::cout << std::endl;
    AForm *form4 = thomas.makeForm("shrubbery creation", "test3");
    
    std::cout << std::endl <<"================================ CLEAN ================================" << std::endl << std::endl;
    (void)form1;
    delete form2;
    delete form3;
    delete form4;
    return 0;
}