#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <vector>
#include <list>
#include <array>
#include <iostream>
#include <algorithm>

class ValueNotFound : public std::exception {
    public:
        virtual const char* what() const throw();
};
#endif