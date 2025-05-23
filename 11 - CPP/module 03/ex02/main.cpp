/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:46:38 by thomas            #+#    #+#             */
/*   Updated: 2025/05/23 13:45:37 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(){
    FragTrap    Thomas("Thomas");
    FragTrap    Louis("Louis");
    FragTrap    Faiz("Faiz");

    Faiz.attack("Thomas");
    Thomas.takeDamage(Thomas.getDamage());
    Thomas.beRepaired(20);
    for (int i = 0; i < 10; i++){
        Thomas.attack("Faiz");
        Faiz.takeDamage(Faiz.getDamage());
    }
    Thomas.highFivesGuys();
    return 0;
}