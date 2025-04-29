/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:26:02 by thomas            #+#    #+#             */
/*   Updated: 2025/04/29 11:16:09 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


class Contact
{
    private :
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    public :
        void    set_contact()
        {
            std::cout << "Enter first name : ";
            std::cin >> contact.first_name;
            std::cout << "Enter last name : ";
            std::cin >> contact.last_name;
            std::cout << "Enter nickname : ";
            std::cin >> contact.nickname;
            std::cout << "Enter phone number : ";
            std::cin >> contact.phone_number;
            std::cout << "Enter darkest secret : ";
            std::cin >> contact.darkest_secret;
        }
        void    display_contact()
        {
            std::cout << "First name : " << first_name << std::endl;
            std::cout << "Last name : "<< last_name << std::endl;
            std::cout << "Nickname : "<< nickname << std::endl;
            std::cout << "Phone Number : "<< phone_number std::endl;
            std::cout << "Darkest secret : "<< darkest_secret << std::endl;
        }
};

void    PhoneBook::set_contact()
{
    PhoneBook   contact;
    
    cout << "Enter first name :";
    cin >> contact.first_name;
    cout << "Enter last name :";
    cin >> contact.last_name;
    cout << "Enter nickname :";
    cin >> contact.nickname;
    cout << "Enter phone number :";
    cin >> contact.phone_number;
    cout << "Enter darkest secret :";
    cin >> contact.darkest_secret;
}

int	ft_strcmp(string s1, string s2)
{
	int	i ;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

int main(int ac, char **av)
{
    if (ft_strcmp(av[1], "ADD") == 0)
        set_contact();
}