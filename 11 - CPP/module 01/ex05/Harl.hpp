/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:47:58 by thomas            #+#    #+#             */
/*   Updated: 2025/05/10 10:10:50 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>

class Harl {
    private:
        void  debug(void);
        void  info(void);
        void  warning(void);
        void  error(void);
    
    public:
        Harl();
        void    complain(std::string level);
};

#endif