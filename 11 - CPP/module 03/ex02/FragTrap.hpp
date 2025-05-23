/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:35:02 by thgaugai          #+#    #+#             */
/*   Updated: 2025/05/23 10:38:12 by thgaugai         ###   ########.fr       */
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