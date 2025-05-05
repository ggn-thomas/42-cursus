/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:26:02 by thomas            #+#    #+#             */
/*   Updated: 2025/05/05 15:13:07 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <stdio.h>

PhoneBook::PhoneBook () { count = 0, oldest = 0 ;}


void	PhoneBook::addContact()
{
	if (count < 8)
	{
		contact[count].setContact();
		count++;
	}
	else
	{
		contact[oldest].reset();
		contact[oldest].setContact();
		oldest = (oldest + 1) % 8;
	}
}

void	PhoneBook::printEmpty(int nb)
{
	while (nb--)
		std::cout << ' ';
}

void PhoneBook::printString(std::string str)
{
	int len = 0;
	int i = 0;
	len = str.length();

	if (len < 10)
	{
		printEmpty(10 - len);
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

int	PhoneBook::handleIndex(std::string index)
{
	if (index.empty())
		return (-1);
	if (!(std::isdigit(index[0])))
		return (-1);
	if (index.length() > 1)
		return (-1);
	return (index[0] - '0');
}


void PhoneBook::displayResult(std::string index)
{
	int	index_int = 0;

	while (1)
	{
		index_int = handleIndex(index);
		if (index_int == -1 || index_int >= count || index_int < 0)
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

void	PhoneBook::displayAllContact()
{
	int i = 0;
	std::string index;

	if (count == 0)
	{
		std::cout << "\033[31mYou haven't got contact in your phonebook !\033[0m" << std::endl;
			return ;
	}
	std::cout << "|     Index| Firstname|  Lastname|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	while (i < count)
	{
		std::cout << "|         " << i << '|';
		printString(contact[i].getFirstname());
		std::cout << '|';
		printString(contact[i].getLastname());
		std::cout << '|';
		printString(contact[i].getNickname());
		std::cout << '|';
		std::cout << '\n';
		i++;
	}
	std::cout << "Enter the index of the contact you want : ";
	std::getline(std::cin, index);
	displayResult(index);
}
