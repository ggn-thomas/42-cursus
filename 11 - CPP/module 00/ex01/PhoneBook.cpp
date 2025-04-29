/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:26:02 by thomas            #+#    #+#             */
/*   Updated: 2025/04/29 16:37:26 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	ft_strlen(std::string str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

class Contact
{
  private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

  public:
	void set_contact()
	{
		std::cout << "Enter first name : ";
		std::cin >> first_name;
		std::cout << "Enter last name : ";
		std::cin >> last_name;
		std::cout << "Enter nickname : ";
		std::cin >> nickname;
		std::cout << "Enter phone number : ";
		std::cin >> phone_number;
		std::cout << "Enter darkest secret : ";
		std::cin >> darkest_secret;
	}
    std::string get_FirstName() { return first_name; }
    
};

class PhoneBook
{
  private:
	int count = 0;
	int oldest = 0;
	Contact contact[8];

  public:
	void add_contact()
	{
		if (count < 8)
		{
			contact[count].set_contact();
			count++;
		}
	}
	void print_empty(int nb)
	{
		while (nb--)
			std::cout << ' ';
	}

	void print_string(std::string str)
	{
		int len = 0;
		int i = 0;
		len = ft_strlen(str);

		if (len < 10)
		{
			print_empty(10 - len);
			std::cout << str;
		}
		else
		{
			while (i <= 9)
			{
				std::cout << str[i];
				i++;
			}
			std::cout << '.';
		}
	}

	void display_allcontact()
	{
		int len = 0;
		int nb_empty = 0;
		int i = 0;

		while (contact[i])
		{
			std::cout << "         " << i << '|';
			print_string(contact[i].first_name);
			std::cout << '|';
			print_string(contact[i].last_name);
			std::cout << '|';
			print_string(contact[i].nickname);
		}
	}
};



int	ft_strcmp(std::string s1, std::string s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

int	main(int ac, char **av)
{
	PhoneBook phonebook;

	if (ft_strcmp(av[1], "ADD") == 0)
		phonebook.add_contact();
	else if (ft_strcmp(av[1], "SEARCH") == 0)
	{
		phonebook.display_allcontact();
	}
	else if (ft_strcmp(av[1], "EXIT") == 0)
		return (0);
}