/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:02:18 by thgaugai          #+#    #+#             */
/*   Updated: 2025/05/29 14:50:30 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal, public Brain {
	private:
		Brain	*Brain;
	public:
		Cat();
		~Cat();
		Cat(Cat &cpy);
		Cat& operator=(const Cat &Cat);

		virtual void	makeSound() const;
};

#endif