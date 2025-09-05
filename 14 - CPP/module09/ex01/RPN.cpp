#include "RPN.hpp"

int parsing(std::string av){
    for (size_t i = 0; i < av.length(); i++){
        if (!isdigit(av[i]) && av[i] != '+' && av[i] != '/' && av[i] != '-' && av[i] != '*'){
            std::cerr << "Error" << std::endl;
            return 0;
        }
        if (isdigit(av[i])){
            if (av[i] > 10){
                std::cerr << "Error: " << av[i] << " is to bigger" << std::endl;
                return 0;
            }
        }
    }
    return 1;
}

void    rpn(const char* rpn){
    if (!parsing(rpn))
        return ;

    std::stack<int> stack;
    for (char c = *rpn; c != 0; *rpn++){
        switch( c ){
            case '+':
                int nA1 =0;
                nA1 = stack.top();
                stack.pop();
                int nA2 = stack.top();
                stack.pop();
                int resultA = nA1 + nA2;\
                stack.push(resultA);
                break;
            case '-':
                int nS1 = stack.top();
                stack.pop();
                int nS2 = stack.top();
                stack.pop();
                int resultS = nS1 - nS2;
                stack.push(resultS);
                break;
            case '/':
                int nD1 = stack.top();
                stack.pop();
                int nD2 = stack.top();
                stack.pop();
                int resultD = nD1 / nD2;
                stack.push(resultD);
                break;
            case '*':
                int nM1 = stack.top();
                stack.pop();
                int nM2 = stack.top();
                stack.pop();
                int resultM = nM1 + nM2;
                stack.push(resultM);
                break;
            default:
                int number = c - '0';
                stack.push(number);
                break;
        }
    }
    int resultFinal = stack.top();
    std::cout << resultFinal << std::endl;
}