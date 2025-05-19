/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:03:51 by thomas            #+#    #+#             */
/*   Updated: 2025/05/16 15:01:10 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class   ScavTrap : public ClapTrap {
    public:
        ScavTrap(void);
        ScavTrap(std::string name);
        ScavTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage);
        ScavTrap(ScavTrap &cpy);
        ScavTrap& operator=(const ScavTrap& ScavTrap);
        ~ScavTrap();
        
        void    guardGate();
        void    attack(const std::string& target);
};
#endif