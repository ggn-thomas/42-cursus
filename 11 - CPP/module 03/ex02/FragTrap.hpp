/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:35:02 by thgaugai          #+#    #+#             */
/*   Updated: 2025/05/26 15:09:55 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap {
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage);
		FragTrap(FragTrap &cpy);
		FragTrap& operator=(const FragTrap &FragTrap);
		~FragTrap();
		
		void	highFivesGuys(void);

};
#endif