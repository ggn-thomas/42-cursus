/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:26:21 by thgaugai          #+#    #+#             */
/*   Updated: 2025/05/28 11:33:16 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
	protected:
		std::string type;

	public:
		Animal();
		Animal(std::string type);
		~Animal();
		Animal(Animal &cpy);
		Animal&	operator=(const Animal &Animal);
		void	makeSound();

};
#endif