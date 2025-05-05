/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:25:20 by thgaugai          #+#    #+#             */
/*   Updated: 2025/05/05 15:10:30 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cstdlib>
class Contact
{
  private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

  public:
	void setContact();
	void reset();
	std::string getFirstname();
	std::string getLastname();
	std::string getNickname();
	std::string getPhonenumber();
	std::string getDarkestsecret();
};

#endif