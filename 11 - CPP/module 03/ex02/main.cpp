/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:33:55 by tblaase           #+#    #+#             */
/*   Updated: 2025/05/26 17:31:31 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

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
		a.takeDamage(a.getDamage());
		a.takeDamage(a.getDamage());
		a.beRepaired(5);
		a.attack("some other other robot");
		b.beRepaired(3);
		for (int i = 0; i < 12; i++)
			b.attack("Cody-clone");
		b.beRepaired(3);
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	std::cout << "\n\n### TESTING SCAVTRAP ###\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		ScavTrap c;
		ScavTrap d("Savage");

		std::cout << "\033[34mTesting\033[0m" << std::endl;
        std::cout << "Here are the initial parameters for : " << c.getName() << " | Damage : " << c.getDamage() << " | HitPoints : " << c.getHitPoints() << " | EnergyPoints : " << c.getEnergyPoints() << std::endl;
        std::cout << "Here are the initial parameters for : " << d.getName() << " | Damage : " << d.getDamage() << " | HitPoints : " << d.getHitPoints() << " | EnergyPoints : " << d.getEnergyPoints() << std::endl;  
		c.attack("CloneTrap");
		for (int i = 0; i < 50; i++)
		 	c.attack("CloneTrap");
		c.beRepaired(22);
		c.takeDamage(21);
		c.beRepaired(22);
		c.guardGate();
		c.guardGate();
		d.attack("Savage-clone");
		d.takeDamage(101);
		d.takeDamage(15);
		d.attack("ScavTrap-clone");
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	std::cout << "\n\n### TESTING FRAGTRAP ###\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		FragTrap e;
		FragTrap f("Chadd");

		std::cout << "\033[34mTesting\033[0m" << std::endl;
        std::cout << "Here are the initial parameters for : " << e.getName() << " | Damage : " << e.getDamage() << " | HitPoints : " << e.getHitPoints() << " | EnergyPoints : " << e.getEnergyPoints() << std::endl;
        std::cout << "Here are the initial parameters for : " << f.getName() << " | Damage : " << f.getDamage() << " | HitPoints : " << f.getHitPoints() << " | EnergyPoints : " << f.getEnergyPoints() << std::endl; 
		e.highFivesGuys();
		e.attack("some random dude");
		e.takeDamage(101);
		e.takeDamage(1);
		e.attack("some random dude");
		f.highFivesGuys();
		// for(int i = 0; i < 101; i++)
		// 	f.attack("FragTrap-clone");
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	return (0);
}