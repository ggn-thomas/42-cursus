#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack() {}

template<typename T>
MutantStack<T>::~MutantStack(){}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &cpy) {
    *this = cpy;
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &cpy){
    if (this != &cpy)
        *this = cpy;
    return *this;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(){
    return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(){
    return (this->c.end());
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const{
    return (this->c.end());
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const{
    return (this->c.end());
}


