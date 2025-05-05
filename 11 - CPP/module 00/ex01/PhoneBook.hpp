/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:07:46 by thgaugai          #+#    #+#             */
/*   Updated: 2025/05/05 16:46:48 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	private:
		int count;
		int oldest;
		Contact contact[8];

	public:
		PhoneBook();
		void addContact();
		void printEmpty(int nb);
		void printString(std::string str);
		void displayResult(std::string index);
		void displayAllContact();
		int handleIndex(std::string index);
};
#endif