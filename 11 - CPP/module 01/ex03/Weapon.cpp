/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:10:38 by thomas            #+#    #+#             */
/*   Updated: 2025/05/08 14:22:43 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weaponType) : weaponType(weaponType) {}

void Weapon::setType(std::string newWeapon){
    this->weaponType = newWeapon;
}

const std::string& Weapon::getType() const {
    return weaponType;
}