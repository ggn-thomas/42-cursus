/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:10:14 by thomas            #+#    #+#             */
/*   Updated: 2025/05/08 11:39:25 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
    private:
        std::string weaponType;
    public:
        Weapon();
        Weapon(std::string weaponType);
        
        const std::string& Weapon::getType();
        void Weapon::setType(std::string newWeapon);
};

#endif