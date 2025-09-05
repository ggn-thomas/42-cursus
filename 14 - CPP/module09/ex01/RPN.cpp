#include "RPN.hpp"

int parsing(std::string &av){
    for (size_t i = 0; i < av.length(); i++){
        if (!isdigit(av[i]) && av[i] != '+' && av[i] != '/' && av[i] != '-' && av[i] != '*'){
            std::cerr << "Error" << std::endl;
            return 0;
        }
    }
}

void    rpn(std::string rpn){
    std::stack<int> stack;

    for (size_t i = 0; i < rpn.length(); i++){

        
    }
}