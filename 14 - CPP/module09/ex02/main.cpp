
#include "PmergeMe.hpp"

int main(int ac, char **av){
    try {
        PmergeMe fordjohnson(ac, av);
        fordjohnson.display();

    }
    catch (std::exception& e){
        std::cerr << e.what() << std::endl;
    };

    return 0;
}