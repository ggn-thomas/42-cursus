
#include "easyfind.hpp"

const char* ValueNotFound::what() const throw() {
    return "Value not found in container!";
}

template<typename T>
typename T::iterator   easyfind(T& container, int val){
    typename T::iterator it = find(container.begin(), container.end(), val);
    if (it == container.end())
        throw (ValueNotFound());
    return it;
}

int main(){
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(24);
    vec.push_back(56);

    std::cout << "__________________________________________________" << std::endl;
    try {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << *it << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << "__________________________________________________" << std::endl;
    try {
        std::vector<int>::iterator it = easyfind(vec, 24);
        std::cout << "Value in the container: "<< *it << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << "__________________________________________________" << std::endl;

    std::array<int, 2> arr = {67, 489};
    try {
        std::array<int, 2>::iterator it = easyfind(arr, 67);
        std::cout << "Value in the container: "<< *it << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << "__________________________________________________" << std::endl;

    std::list<int> lst;
    lst.push_back(67);
    lst.push_back(6793);
    lst.push_back(0);
    try {
        std::list<int>::iterator it = easyfind(lst, 67);
        std::cout << "Value in the container: "<< *it << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}