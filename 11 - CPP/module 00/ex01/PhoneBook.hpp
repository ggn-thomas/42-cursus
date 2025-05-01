/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:07:46 by thgaugai          #+#    #+#             */
/*   Updated: 2025/05/01 18:03:25 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "contact.hpp"

class PhoneBook
{
	private:
		int count;
		int oldest;
		Contact contact[8];

	public:
		PhoneBook();
		void add_contact();
		void print_empty(int nb);
		void print_string(std::string str);
		void display_result(std::string index);
		void display_allcontact();
		int handle_index(std::string index);
};
#endif