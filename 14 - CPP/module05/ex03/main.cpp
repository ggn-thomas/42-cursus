/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:30:58 by thomas            #+#    #+#             */
/*   Updated: 2025/07/31 18:29:03 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Intern.hpp"

int main()
{
    Intern Thomas;
    AForm*  form1 = Thomas.makeForm("robotomy request", "Bender");

    std::cout << form1->getName() << std::endl;

    delete form1;
    return 0;
}