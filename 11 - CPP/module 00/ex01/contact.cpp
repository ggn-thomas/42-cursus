/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:30:27 by thgaugai          #+#    #+#             */
/*   Updated: 2025/05/01 17:25:15 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void	Contact::set_contact()
{
	while(firstName.empty())
	{
		std::cout << "Enter first name : ";
		std::getline(std::cin, firstName);
		if (std::cin.eof())
			exit(0);
		if (firstName.empty())
			std::cout << "\033[31mYou have to fill in the input !\033[0m\n";
	}
	while(lastName.empty())
	{
		std::cout << "Enter last name : ";
		std::getline(std::cin, lastName);
		if (std::cin.eof())
			exit(0);
		if (lastName.empty())
			std::cout << "\033[31mYou have to fill in the input !\033[0m\n";
	}
	while(nickname.empty())
	{
		std::cout << "Enter nickname : ";
		std::getline(std::cin, nickname);
		if (std::cin.eof())
			exit(0);
		if (nickname.empty())
			std::cout << "\033[31mYou have to fill in the input !\033[0m\n";
	}
	while(phoneNumber.empty())
	{
		std::cout << "Enter phone number : ";
		std::getline(std::cin, phoneNumber);
		if (std::cin.eof())
			exit(0);
		if (phoneNumber.empty())
			std::cout << "\033[31mYou have to fill in the input !\033[0m\n";
	}
	while(darkestSecret.empty())
	{
		std::cout << "Enter darkest secret : ";
		std::getline(std::cin, darkestSecret);
		if (std::cin.eof())
			exit(0);
		if (darkestSecret.empty())
			std::cout << "\033[31mYou have to fill in the input !\033[0m\n";
	}
}

std::string Contact::getFirstname()
{
	return (firstName);
}

std::string Contact::getLastname()
{
	return (lastName);
}

std::string Contact::getNickname()
{
	return (nickname);
}

std::string Contact::getPhonenumber()
{
	return (phoneNumber);
}

std::string Contact::getDarkestsecret()
{
	return (darkestSecret);
}
