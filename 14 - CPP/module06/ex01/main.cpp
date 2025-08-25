/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:43:21 by thomas            #+#    #+#             */
/*   Updated: 2025/08/25 16:49:38 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(){
    Data *data = new Data;
    
    data->value = 42;
    data->name = "school";
    data->price = 0;

    uintptr_t raw = Serializer::serialize(data);
    Data *test = Serializer::deserialize(raw);

    std::cout << "value: " << test->value << std::endl;
    std::cout << "name: " << test->name << std::endl;
    std::cout << "price: " << test->price << std::endl;

    delete data;

    return 0;
}