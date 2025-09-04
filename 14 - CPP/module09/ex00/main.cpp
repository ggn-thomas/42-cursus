#include "BitcoinExchange.hpp"

void    addLineToMap(std::string line){
    std::map<std::string, double> _csv;

    std::string date = line.substr(0, 9);
    std::string valueS = line.substr(13, line.length() - 13);
    int value = atoi(valueS.c_str());

    _csv[date] = value;
    
}


int checkValidDate(std::string line){
    if (line.empty())
        return 1;
    std::string dayS = line.substr(5, 2);
    int day = atoi(dayS.c_str());
    if (day > 31){
        std::cerr << "Error: bad input => " << line << std::endl << "Enter valid day!" << std::endl;
        return 0;
    }
    std::string monthS = line.substr(8, 2);
    int month = atoi(monthS.c_str());
    if (month > 12){
        std::cerr << "Error: bad input => " << line << std::endl << "Enter valid month!" << std::endl;
        return 0;
    }
    std::string valS = line.substr(13, line.length() - 13);
    long val = atol(valS.c_str());
    if (val > 2147483647 || val <= 0){
        std::cerr << "Error: bad input => " << line << std::endl;
        return 0;
    }
    return 1;
}

int parsing(std::string line){
    if (line.empty()){
        std::cerr << "Error: bad input => (empty)" << std::endl;
        return -1;
    }
    if (line[4] != '-' || line[7] != '-' || line[10] != ' ' || line[11] != '|' || line[12] != ' '){
        size_t sep = line.find('-');
        std::string yearS = line.substr(0, sep);
        long year = atoi(yearS.c_str());
        if (year > 9999)
            std::cerr << "Error: bad input => " << line << std::endl << "Max year is 9999!" << std::endl;
        else
            std::cerr << "Error: bad input => " << line << std::endl;
        return -1;  
    }
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
    if (!isdigit(line[line.length() - 1]) && line[line.length() - 1] != '\n'){
        std::cerr << "Error: bad input => " << line << std::endl;
        return -1;
    }
    if (!checkValidDate(line))
        return 1;
    addLineToMap(line);
    return 1;
}

int getLine(std::string file){
    std::string line;

    std::ifstream csvFile(file.c_str());
    if (!csvFile.is_open()){
        std::cerr << "Error: could not open file." << std::endl;
        return 0;
    }
    while (getline(csvFile, line)){
        // std::cout << line << std::endl;
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