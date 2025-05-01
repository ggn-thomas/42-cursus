/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:26:02 by thomas            #+#    #+#             */
/*   Updated: 2025/05/01 18:04:59 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

PhoneBook::PhoneBook () { count = 0, oldest = 0 ;}

void	PhoneBook::add_contact()
{
	if (count < 8)
	{
		contact[count].set_contact();
		count++;
	}
	else
	{
		contact[oldest].set_contact();
		oldest = (oldest + 1) % 8;
	}
}

void	PhoneBook::print_empty(int nb)
{
	while (nb--)
		std::cout << ' ';
}

void PhoneBook::print_string(std::string str)
{
	int len = 0;
	int i = 0;
	len = str.length();

	if (len < 10)
	{
		print_empty(10 - len);
		std::cout << str;
	}
	else
	{
		while (i < 9)
		{
			std::cout << str[i];
			i++;
		}
		std::cout << '.';
	}
}

int	PhoneBook::handle_index(std::string index)
{
	if (index.isAlpha())
		return (-1);
	if (index.length() > 1)
		return (-1);
	return (index + '0');
}

void PhoneBook::display_result(std::string index)
{
	int	num = 1000000;

	while ((!(num < count)) || handle_index(index) == -1)
	{
		std::cout << "\033[31mInvalid index ! Retry with another value : \033[0m";
		std::cin>>index;
		if (std::cin.eof())
			exit(0);
	}
	std::cout << "Here is the contact number : " << index << std::endl;
	std::cout << contact[index].getFirstname() << std::endl;
	std::cout << contact[index].getLastname() << std::endl;
	std::cout << contact[index].getNickname() << std::endl;
	std::cout << contact[index].getPhonenumber() << std::endl;
	std::cout << contact[index].getDarkestsecret() << std::endl;
}

void	PhoneBook::display_allcontact()
{
	int i = 0;
	std::string index;

	if (count == 0)
	{
		std::cout << "\033[31mYou haven't got contact in your phonebook !\033[0m\n" << std::endl;
			return ;
	}
	while (i < count)
	{
		std::cout << "|     Index| Firstname|  Lastname|  Nickname|" << std::endl;
		std::cout << "|----------|----------|----------|----------|" << std::endl;
		std::cout << "|         " << i << '|';
		print_string(contact[i].getFirstname());
		std::cout << '|';
		print_string(contact[i].getLastname());
		std::cout << '|';
		print_string(contact[i].getNickname());
		std::cout << '|';
		std::cout << '\n';
		i++;
	}
	std::cout << "Enter the index of the contact you want : ";
	std::cin >> index;
	display_result(index);
}
