/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:33:55 by tblaase           #+#    #+#             */
/*   Updated: 2025/05/26 17:31:50 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	std::cout << "### TESTING CLAPTRAP ###\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		ClapTrap a;
		ClapTrap b("Cody");

		std::cout << "\033[34mTesting\033[0m" << std::endl;
        std::cout << "Here are the initial parameters for : " << a.getName() << " | Damage : " << a.getDamage() << " | HitPoints : " << a.getHitPoints() << " | EnergyPoints : " << a.getEnergyPoints() << std::endl;
        std::cout << "Here are the initial parameters for : " << b.getName() << " | Damage : " << b.getDamage() << " | HitPoints : " << b.getHitPoints() << " | EnergyPoints : " << b.getEnergyPoints() << std::endl; 
		a.attack("some other robot");
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		a.attack("some other other robot");
		b.beRepaired(3);
		for (int i = 0; i < 12; i++)
			b.attack("Cody-clone");
		b.beRepaired(3);
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	return (0);
}