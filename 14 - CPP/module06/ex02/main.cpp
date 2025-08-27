/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgaugai <thgaugai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:38:37 by thomas            #+#    #+#             */
/*   Updated: 2025/08/27 11:40:59 by thgaugai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base* generate(void) {
    int random = std::rand() % 3;

    switch (random){
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
    }
    return 0;
}

void    identify(Base* p){
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p){
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return ;
    }
    catch (std::exception&){}
    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return ;
    }
    catch (std::exception&) {}
    try {
        C& c =dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return ;
    }
    catch (std::exception&) {}
}

int main() {
    Base *ptr = generate();
    Base &ref = *ptr;
    std::cout << "identify(ptr) : ";
    identify(ptr);
    std::cout << "identify(ref): ";
    identify(ref);
    
    delete ptr;

    return 0;
}