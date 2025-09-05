#include "BitcoinExchange.hpp"

void    loadDatabase(std::map<std::string, double> &database){
    std::string line;
    std::string file = "data.csv";
    std::ifstream fileData(file.c_str());

    if (!fileData.is_open())
    {
        std::cout << "Error: failed to open data.csv!" << std::endl;
        return ;
    }
    while (getline(fileData, line)){
        size_t dot = line.find(',');
        std::string key = line.substr(0, dot);
        std::string valS = line.substr(dot + 1, line.length() - dot);
        double value = atof(valS.c_str());
        database[key] = value;
    }
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
    if (val > 1000 || val < 0){
        std::cerr << "Error: bad input => " << line << std::endl;
        return 0;
    }
    return 1;
}

int checkValidSyntax(std::string line){
    if (line.empty()){
        std::cerr << "Error: bad input => (empty)" << std::endl;
        return 0;
    }
    if (line[4] != '-' || line[7] != '-' || line[10] != ' ' || line[11] != '|' || line[12] != ' '){
        size_t sep = line.find('-');
        std::string yearS = line.substr(0, sep);
        long year = atoi(yearS.c_str());
        if (year > 9999)
            std::cerr << "Error: bad input => " << line << std::endl << "Max year is 9999!" << std::endl;
        else
            std::cerr << "Error: bad input => " << line << std::endl;
        return 0;  
    }
    for (size_t i = 0; i < line.length(); i++){
        char current = line[i];
        bool isValid = isdigit(current) || current == '-' || current == ' ' || current == '|' || current == '.';
        if (!isValid){
            std::cerr << "Error: bad input => " << line << std::endl;
            return 0;
        }
        if (i+1 < line.length()){
            if (current == '.' && !isdigit(line[i+1])){
                std::cerr << "Error: bad input => " << line << std::endl;
                return 0;
            }
            else if (current == ' ' && !isdigit(line[i+1]) && line[i + 1] != '|'){
                std::cerr << "Error: bad input => " << line << std::endl;
                return 0;
            }
            else if (current == '-' && !isdigit(line[i+1])){
                std::cerr << "Error: bad input => " << line << std::endl;
                return 0;
            }
            else if (current == '|' && !isdigit(line[i+1]) && line[i + 1] != ' '){
                std::cerr << "Error: bad input => " << line << std::endl;
                return 0;
            }
        }
    }
    if (!isdigit(line[line.length() - 1]) && line[line.length() - 1] != '\n'){
        std::cerr << "Error: bad input => " << line << std::endl;
        return 0;
    }
    return 1;
}

void    findPrice(std::string line, std::map<std::string, double>& db){
    double price = 0;
    int flag = 0;

    std::string date = line.substr(0, 9);
    std::string balanceS = line.substr(13, line.length() - 13);
    double balance = atof(balanceS.c_str());

    std::map<std::string, double>::const_iterator exact = db.find(date);
    if (exact != db.end()){
        price = exact->second;
        flag = 1;
    }
    std::map<std::string, double>::const_iterator it = db.lower_bound(date);
    if (!flag){
        if (it == db.begin()){
            price = it->second;
        }
        else{
            --it;
            price = it->second;
        }
    }
    std::cout << date << " => " << balance << " = " << price * balance << std::endl;
}

int parsing(std::string line, std::map<std::string, double> &db){
    if (!checkValidSyntax(line))
        return 1;
    if (!checkValidDate(line))
        return 1;
    findPrice(line, db);
    return 1;
}

int getLine(std::string file){
    std::string line;
    std::map<std::string, double> db;

    std::ifstream csvFile(file.c_str());
    if (!csvFile.is_open()){
        std::cerr << "Error: could not open file." << std::endl;
        return 0;
    }
    loadDatabase(db);
    while (getline(csvFile, line)){
        parsing(line, db);
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