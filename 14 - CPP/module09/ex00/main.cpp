#include "BitcoinExchange.hpp"

int parsing(std::string line){
    if (line.empty()){
        std::cerr << "Error: bad input => (empty)" << std::endl;
        return -1;
    }
    // size_t pipe = line.find('|');
    // size_t sep = line.find(0, 3, '-');
    // size_t sep2 = line.
    // std::cout << line[4] << line[7] << line[12] << line[11] << line[10] << std::endl;
    for (size_t i = 0; i < line.length(); i++){
        char current = line[i];
        bool isValid = isdigit(current) || current == '-' || current == ' ' || current == '|' || current == '.';
        if (!isValid){
            std::cerr << "Error: bad input => " << line << std::endl;
            return -1;
        }
        if (i+1 < line.length()){
            if (current == '.' && !isdigit(line[i+1])){
                std::cerr << "Error: bad input => " << line << std::endl;
                return -1;
            }
            else if (current == ' ' && !isdigit(line[i+1]) && line[i + 1] != '|'){
                std::cerr << "Error: bad input => " << line << std::endl;
                return -1;
            }
            else if (current == '-' && !isdigit(line[i+1])){
                std::cerr << "Error: bad input => " << line << std::endl;
                return -1;
            }
            else if (current == '|' && !isdigit(line[i+1]) && line[i + 1] != ' '){
                std::cerr << "Error: bad input => " << line << std::endl;
                return -1;
            }
        }
    }
    return 1;
}


int getLine(std::string file){
    //BitcoinExchange btc;
    std::string line;

    std::ifstream csvFile(file.c_str());
    if (!csvFile.is_open()){
        std::cerr << "Error: could not open file." << std::endl;
        return 0;
    }
    while (getline(csvFile, line)){
        std::cout << line << std::endl;
        parsing(line);
    }
    return 1;
    
}


int main(int ac, char **av){
    if (ac != 2){
        std::cerr << "Error: could not open file." << std::endl;
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