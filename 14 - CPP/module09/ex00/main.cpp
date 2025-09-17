#include "BitcoinExchange.hpp"

int main(int ac, char **av){
    if (ac != 2){
        std::cerr << "Error: number of arguments is incorrect!" << std::endl;
        return -1;
    }
    std::string file = av[1];
    if (file.find(".csv") == std::string::npos){
        std::cerr << "Error: could not open file." << std::endl;
        return -1;
    }
    getLine(file);
    return 0;
}