/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:25:12 by thgaugai          #+#    #+#             */
/*   Updated: 2025/05/06 17:48:02 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string	string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string& stringREF = string;

	std::cout << "Memory address of string : " << &string << std::endl;
	std::cout << "Memory address held by stringPTR : "<< &stringPTR << std::endl;
	std::cout << "Memory address held by stringREF : "<< &stringREF << std::endl;

	std::cout << "Value of the string : " << string << std::endl;
	std::cout << "Value pointed to by stringPTR : " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF : " << stringREF << std::endl;
}