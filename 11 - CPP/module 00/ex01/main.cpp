/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:13:17 by thgaugai          #+#    #+#             */
/*   Updated: 2025/05/05 14:00:51 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook phonebook;
	std::string command;

	while (1)
	{
		std::cout<< "Enter command (ADD, SEARCH, EXIT)" << std::endl;
		std::getline(std::cin, command);
		if (std::cin.eof())
			return (1);
		if (command == "ADD")
		{
			phonebook.addContact();
			std::cout << "\033[32mContact successfully added !\033[0m\n" << std::endl;
		}
		else if (command == "SEARCH")
			phonebook.displayAllContact();
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Invalid command. Avaible commands : ADD, SEARCH, EXIT" << std::endl;
	}
	return (1);
}