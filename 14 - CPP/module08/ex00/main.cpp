
#include "easyfind.hpp"

const char* ValueNotFound::what() const throw() {
    return "Value not found in container!";
}

int main(){
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(24);
    vec.push_back(56);

    std::cout << "__________________________________________________" << std::endl;
    try {
        std::vector<int>::iterator it = easyFind(vec, 3);
        std::cout << *it << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << "__________________________________________________" << std::endl;
    try {
        std::vector<int>::iterator it = easyFind(vec, 24);
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
        std::list<int>::iterator it = easyFind(lst, 67);
        std::cout << "Value in the container: "<< *it << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}