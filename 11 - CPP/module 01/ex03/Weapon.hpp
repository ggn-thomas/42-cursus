/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:10:14 by thomas            #+#    #+#             */
/*   Updated: 2025/05/10 14:02:43 by thgaugai         ###   ########.fr       */
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

        const std::string&  getType(void) const;
        void    setType(std::string newWeapon);
};

#endif