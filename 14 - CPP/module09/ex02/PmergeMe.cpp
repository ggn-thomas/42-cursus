#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av) : _inputVector(), _inputDeque(){
    parsing(ac, av);
};

PmergeMe::PmergeMe(const PmergeMe& cpy) : _inputVector(cpy._inputVector), _inputDeque(cpy._inputDeque) {
}

PmergeMe PmergeMe::operator=(const PmergeMe& cpy) {
    if (this != &cpy){
        _inputDeque = cpy._inputDeque;
        _inputVector = cpy._inputVector;
    }
    return *this;
}

PmergeMe::~PmergeMe(){
}

const char* PmergeMe::HandlerError::what() const throw () {
    return "Error";
}

void    PmergeMe::parsing(int ac, char **av){
    if (ac <= 1)
        throw (HandlerError());
    long long number = 0;
    for (int i = 1; av[i]; i++){
        for (int j = 0; av[i][j]; j++){
            if (!isdigit(av[i][j]))
                throw (HandlerError());
        }
        number = atol(av[i]);
        if (number > 2147483647 || number < -2147483648)
            throw (HandlerError());
        _inputVector.push_back(number);
        _inputDeque.push_back(number);
    }
}

void    PmergeMe::display(){
    std::cout << "Before:  ";
    for (size_t i = 0; i < _inputVector.size(); i++){
        std::cout << _inputVector[i];
        if (i < (_inputVector.size() - 1))
            std::cout << " ";
    }

    std::cout << std::endl;
    std::vector<int> vectorSort = _inputVector;
    clock_t startVector = clock();
    fordJohnsonSort(vectorSort);
    clock_t endVector = clock();
    double vectorTime = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 100000.0;

    std::deque<int> dequeSort = _inputDeque;
    clock_t startDeque = clock();
    fordJohnsonSort(dequeSort);
    clock_t endDeque = clock();
    double dequeTime = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 100000.0;

    std::cout << "After:   ";
    for (size_t i = 0; i < _inputVector.size(); i++){
        std::cout << vectorSort[i];
        if (i < vectorSort.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of   " << _inputVector.size() << " elements with std::vector :  " << std::fixed << std::setprecision(5) << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of   " << _inputDeque.size() << " elements with std::deque :  " << std::fixed << std::setprecision(5) << dequeTime << " us" << std::endl;
}

// J(n) = J(n-1) + 2 * J(n-2)
std::vector<size_t> PmergeMe::Jacobsthal(size_t pendSize) const {
    if (pendSize == 0)
        return std::vector<size_t>();

    // calcul la suite de jacobsthal
    std::vector<size_t> jacob;
    jacob.push_back(1);
    if (pendSize > 1){
        jacob.push_back(1);
        size_t prev = 1; // = J(n-2) -> l'avant-dernier nombre calculé.
        size_t curr = 1; // = J(n-1) -> le dernier nombre calculé.
        while (true){
            size_t next = curr + 2 * prev; // = J(1) -> le prochain nombre calculé.
            if (next > pendSize) // dès qu'on dépasse la taille de ma liste d'élément à insérer.
                break ;
            jacob.push_back(next);
            prev = curr;
            curr = next;
        }
    }

    std::vector<size_t> insertionOrder;
    size_t inserted = 0;
    for (size_t i = 1; i < jacob.size(); ++i){
        size_t current = jacob[i];
        for (size_t j = current; j > inserted && j <= pendSize; --j){
            insertionOrder.push_back(j-1); // convertir en index
        }
        inserted = current;
    }

    for (size_t j = pendSize; j > inserted; --j){
        insertionOrder.push_back(j - 1);
    }
    
    return insertionOrder;
}

// ************************************************************************************************* //
//                                      FORD JOHNSON VECTOR                                          //
// ************************************************************************************************* //

void    PmergeMe::insertPend(std::vector<int>& main, std::vector<int>& pend){
    if (pend.empty())
        return ;

    std::vector<size_t> insertionOrder = Jacobsthal(pend.size());
    for (size_t i = 0; i < insertionOrder.size(); ++i){
        size_t index = insertionOrder[i];
        if (index >= pend.size())
            continue ;
        int element = pend[index];
        
        std::vector<int>::iterator insertPos = std::lower_bound(main.begin(), main.end(), element);
        main.insert(insertPos, element);
    }
}


void    PmergeMe::sortPairs(std::vector<std::pair<int, int> >& pairs){
    if (pairs.size() <= 1)
        return;
    std::vector<int> firstElements;
    for (size_t i = 0; i < pairs.size() ; i++){
        firstElements.push_back(pairs[i].first);
    }
    fordJohnsonSort(firstElements);

    std::vector<std::pair<int, int> > sortedPairs;
    for (size_t i = 0; i < firstElements.size(); ++i){
        for (size_t j = 0; j < pairs.size(); ++j){
            if (pairs[j].first == firstElements[i]){
                sortedPairs.push_back(pairs[j]);
                pairs[j].first = -1;
                break ;
            }
        }
    }
    pairs = sortedPairs;
}


void PmergeMe::fordJohnsonSort(std::vector<int>& input){
    if (input.size() <= 1)
        return ;
    
    bool hasUnpaired = 0;
    int unpaired = 0;
    if (input.size() % 2)
        hasUnpaired = 1;
    if (hasUnpaired){
        unpaired = input.back();
        input.pop_back();
    }
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < input.size() ; i+=2){
        int a = input[i];
        int b = input[i+1];

        if (a >= b){
            pairs.push_back(std::make_pair(a,b));
        }
        else{
            pairs.push_back(std::make_pair(b,a));
        }
    }
    sortPairs(pairs);

    std::vector<int> main;
    std::vector<int> pend;

    if (!pairs.empty()){
        main.push_back(pairs[0].second);
        for (size_t i = 0; i < pairs.size(); ++i){
            main.push_back(pairs[i].first);
        }
        for (size_t i = 1; i < pairs.size() ; ++i){
            pend.push_back(pairs[i].second);
        }
    }
    if (hasUnpaired)
        pend.push_back(unpaired);
    
    insertPend(main, pend);
    input = main;
}

// ************************************************************************************************* //
//                                      FORD JOHNSON DEQUE                                          //
// ************************************************************************************************* //

void    PmergeMe::insertPend(std::deque<int>& main, std::deque<int>& pend){
    if (pend.empty())
        return ;
    
    std::vector<size_t> insertionOrder = Jacobsthal(pend.size());
    for (size_t i = 0; i < insertionOrder.size(); ++i){
        size_t index = insertionOrder[i];
        if (index >= pend.size())
            continue ;
        int element = pend[index];
        
        std::deque<int>::iterator insertPos = std::lower_bound(main.begin(), main.end(), element);
        main.insert(insertPos, element);
    }
}


void    PmergeMe::sortPairs(std::deque<std::pair<int, int> >& pairs){
    if (pairs.size() <= 1)
        return;
    std::deque<int> firstElements;
    for (size_t i = 0; i < pairs.size() ; i++){
        firstElements.push_back(pairs[i].first);
    }
    fordJohnsonSort(firstElements);

    std::deque<std::pair<int, int> > sortedPairs;
    for (size_t i = 0; i < firstElements.size(); ++i){
        for (size_t j = 0; j < pairs.size(); ++j){
            if (pairs[j].first == firstElements[i]){
                sortedPairs.push_back(pairs[j]);
                pairs[j].first = -1;
                break ;
            }
        }
    }
    pairs = sortedPairs;
}


void PmergeMe::fordJohnsonSort(std::deque<int>& input){
    if (input.size() <= 1)
        return ;
    
    bool hasUnpaired = 0;
    int unpaired = 0;
    if (input.size() % 2)
        hasUnpaired = 1;
    if (hasUnpaired){
        unpaired = input.back();
        input.pop_back();
    }
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < input.size() ; i+=2){
        int a = input[i];
        int b = input[i+1];

        if (a >= b){
            pairs.push_back(std::make_pair(a,b));
        }
        else{
            pairs.push_back(std::make_pair(b,a));
        }
    }
    sortPairs(pairs);

    std::deque<int> main;
    std::deque<int> pend;

    if (!pairs.empty()){
        main.push_back(pairs[0].second);
        for (size_t i = 0; i < pairs.size(); ++i){
            main.push_back(pairs[i].first);
        }
        for (size_t i = 1; i < pairs.size() ; ++i){
            pend.push_back(pairs[i].second);
        }
    }
    if (hasUnpaired)
        pend.push_back(unpaired);
    
    insertPend(main, pend);
    input = main;
}