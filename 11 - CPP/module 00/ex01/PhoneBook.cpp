/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:26:02 by thomas            #+#    #+#             */
/*   Updated: 2025/05/04 14:33:11 by thomas           ###   ########.fr       */
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
	if (index.empty())
		return (-1);
	if (!(std::isdigit(index[0])))
		return (-1);
	if (index.length() > 1)
		return (-1);
	return (index[0] - '0');
}


void PhoneBook::display_result(std::string index)
{
	int	index_int = 0;
		
	while (1)
	{
		index_int = handle_index(index);
		if (index_int == -1)
		{
			std::cout << "\033[31mPlease enter valid index!\033[0m" << std::endl;
			index.clear();
			std::cout << "Enter the index of the contact you want : ";
			std::getline(std::cin, index);
			if (std::cin.eof())
				exit(0);
			continue;
		}
		if (index_int >= count || index_int < 0)
		{
			std::cout << "\033[31mPlease enter valid index!\033[0m" << std::endl;
			index.clear();
			std::cout << "Enter the index of the contact you want : ";
			std::getline(std::cin, index);
			if (std::cin.eof())
				exit(0);
			continue;
		}
		else
			break;
	}
	std::cout << "Here is the contact number : " << index << std::endl;
	std::cout << contact[index_int].getFirstname() << std::endl;
	std::cout << contact[index_int].getLastname() << std::endl;
	std::cout << contact[index_int].getNickname() << std::endl;
	std::cout << contact[index_int].getPhonenumber() << std::endl;
	std::cout << contact[index_int].getDarkestsecret() << std::endl;
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
	std::cout << "|     Index| Firstname|  Lastname|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	while (i < count)
	{
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
	std::getline(std::cin, index);
	display_result(index);
}
