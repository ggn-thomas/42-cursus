/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:02:49 by thomas            #+#    #+#             */
/*   Updated: 2025/09/01 14:33:58 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
template<typename T_tab, typename T_function>
void    iter(T_tab *tab, size_t len, T_function& function) {
    for (size_t i = 0; i < len - 1; i++)
        function(tab[i]);
}
#endif