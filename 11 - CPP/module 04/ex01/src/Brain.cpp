/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:27:09 by thomas            #+#    #+#             */
/*   Updated: 2025/05/29 14:37:39 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain(){
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain(){
    std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(Brain &cpy){
    if (this != &cpy)
        *this = cpy;
}

Brain& Brain::operator=(const Brain &b){
    *this = b;
    return (*this);
}

void Brain::setIdeas(std::string idea, int i){
    this->ideas[i] = idea;
}

std::string    Brain::getIdeas(int i){
    return this->ideas[i];
}
