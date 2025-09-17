#include "RPN.hpp"

int parsing(std::string av){

    for (size_t i = 0; i < av.length() ; i++){
        if (!isdigit(av[i]) && av[i] != '+' && av[i] != '/' && av[i] != '-' && av[i] != '*' && av[i] != ' '){
            std::cout << "Error: bad syntax!" << std::endl;
            return 0;
        }
        if (i < av.length()){
            if (isdigit(av[i]) && isdigit(av[i+1])){
                std::cerr << "Error: to bigger number" << std::endl;
                return 0;
            }
        }
    }
    return 1;
}

int checkSyntax(std::string rpn){
    size_t i = 0;

    while (rpn[i] == ' ')
        i++;
    if (i == rpn.length() || !isdigit(rpn[i])){
        std::cerr << "Error: bad syntax!" << std::endl;
        return 0;
    }
    return 1;
}

void    rpn(char* rpn){
    if (!parsing(rpn) || !checkSyntax(rpn)){
        return ;
    }
    std::stack<int> stack;
    for (int i = 0; rpn[i]; i++){
        char c = rpn[i];
        switch( c ){
            case '+':
            {
                if (stack.size() < 2){
                    std::cerr << "Error: bad syntax" << std::endl;
                    return ;
                }
                int nA1 =0;
                nA1 = stack.top();
                stack.pop();
                int nA2 = stack.top();
                stack.pop();
                int resultA = nA1 + nA2;
                stack.push(resultA);
                break;
            }
            case '-':
            {   
                if (stack.size() < 2){
                    std::cerr << "Error: bad syntax" << std::endl;
                    return ;
                }
                int nS1 = stack.top();
                stack.pop();
                int nS2 = stack.top();
                stack.pop();
                int resultS =  nS2 - nS1;
                stack.push(resultS);
                break;
            }
            case '/':
            {
                if (stack.size() < 2){
                    std::cerr << "Error: bad syntax" << std::endl;
                    return ;
                }
                int nD1 = stack.top();
                stack.pop();
                int nD2 = stack.top();
                stack.pop();
                int resultD = nD2/nD1;
                stack.push(resultD);
                break;
            }
            case '*':
            {
                if (stack.size() < 2){
                    std::cerr << "Error: bad syntax" << std::endl;
                    return ;
                }
                int nM1 = stack.top();
                stack.pop();
                int nM2 = stack.top();
                stack.pop();
                int resultM = nM1 * nM2;
                stack.push(resultM);
                break;
            }
            case ' ':
            {
                break;
            }
            default:
            {
                int number = (c - '0');
                stack.push(number);
                break;
            }
        }
    }
    int resultFinal = stack.top();
    std::cout << resultFinal << std::endl;
}