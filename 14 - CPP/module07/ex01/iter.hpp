/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:02:49 by thomas            #+#    #+#             */
/*   Updated: 2025/08/26 11:03:25 by thomas           ###   ########.fr       */
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