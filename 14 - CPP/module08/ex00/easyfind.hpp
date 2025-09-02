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

template<typename T>
typename T::iterator   easyfind(T& container, int val){
    typename T::iterator it = find(container.begin(), container.end(), val);
    if (it == container.end())
        throw (ValueNotFound());
    return it;
}

#endif