#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <sstream>

class PmergeMe {
    public:
        PmergeMe(int ac, char **av);
        ~PmergeMe();

        void parsing (int ac, char **av);
        void display();
        std::vector<size_t> Jacobsthal(size_t pend) const ;

        // vector
        void    fordJohnsonSort(std::vector<int>& input);
        void    sortPairs(std::vector<std::pair<int, int> >& pairs);
        void    insertPend(std::vector<int>& main, std::vector<int>& pend);

        //deque
        void    insertPend(std::deque<int>& main, std::deque<int>& pend);
        void    sortPairs(std::deque<std::pair<int, int> >& pairs);
        void    fordJohnsonSort(std::deque<int>& input);
        
    private:
        std::vector<int>    _inputVector;
        std::deque<int>     _inputDeque;

    class handlerError : public std::exception {
        public:
            const char* what() const throw();
    };

};
#endif