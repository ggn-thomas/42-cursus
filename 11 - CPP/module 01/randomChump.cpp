/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:56:42 by thgaugai          #+#    #+#             */
/*   Updated: 2025/05/05 16:56:28 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	zombie;

	zombie.name = name;
	std::cout << "The zombie " << zombie.name << " has just been created" << std::endl;
	name.clear();
	std::cout << "The zombie has just been destroyed" << std::endl;
}