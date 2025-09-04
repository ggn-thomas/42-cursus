#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <limits>
#include <cstdlib>

class BitcoinExchange {
    private:
        std::map<std::string, double> _csv;

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& cpy);
        BitcoinExchange operator=(const BitcoinExchange& cpy);
};

#endif