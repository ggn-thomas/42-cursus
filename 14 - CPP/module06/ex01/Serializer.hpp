/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:16:54 by thomas            #+#    #+#             */
/*   Updated: 2025/08/25 16:54:11 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>


typedef struct Data {
    int value;
    double price;
    std::string name;
}   t_data;


class Serializer {
    private:
        Serializer();
        ~Serializer();
        Serializer(const Serializer &cpy);
        Serializer& operator=(const Serializer &serializer);
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
        
};

#endif