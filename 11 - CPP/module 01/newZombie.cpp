/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:05:15 by thgaugai          #+#    #+#             */
/*   Updated: 2025/05/05 16:14:37 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*NewZombie(std::string name)
{
	 Zombie	*zombie;

	 zombie = new Zombie(name);
	 return zombie;
}