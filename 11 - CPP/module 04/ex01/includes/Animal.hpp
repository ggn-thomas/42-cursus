/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:26:21 by thgaugai          #+#    #+#             */
/*   Updated: 2025/05/29 14:51:09 by thgaugai         ###   ########.fr       */
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
		virtual ~Animal();
		Animal(Animal &cpy);
		Animal&	operator=(const Animal &Animal);

		virtual void	makeSound() const;
		std::string	getType() const;
		virtual void	setIdeas(std::string idea, int i) const;
		virtual std::string	getIdeas(int i) const;

};
#endif