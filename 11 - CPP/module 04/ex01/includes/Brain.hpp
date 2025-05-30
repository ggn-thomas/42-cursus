/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:27:29 by thomas            #+#    #+#             */
/*   Updated: 2025/05/29 14:44:12 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
    private:
        std::string ideas[100];
    public:
        Brain();
        ~Brain();
        Brain(Brain &cpy);
        Brain& operator=(const Brain &b);

    virtual void    setIdeas(std::string idea, int i);
    virtual std::string    getIdeas(int i);

};

#endif