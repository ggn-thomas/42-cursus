/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:10:38 by thomas            #+#    #+#             */
/*   Updated: 2025/05/08 11:38:21 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weapon) {}

void Weapon::setType(std::string newWeapon){
    weaponType = newWeapon;
}

const std::string& Weapon::getType() const {
    return weaponType;
}