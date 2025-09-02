
#include "MutantStack.hpp"

int main()
{
    std::cout << "-------------------------------------SUBJECT MAIN-------------------------------------" << std::endl << std::endl; 
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);


    std::cout << "-------------------------------------TEST CONSTANT ITERATOR-------------------------------------" << std::endl << std::endl;

    // const MutantStack<int>& const_mstack = mstack;
    // MutantStack<int>::const_iterator it_const = const_mstack.begin();
    // *it_const = 999;
    // return 0;

    std::cout << "-------------------------------------PERSONNAL MAIN-------------------------------------" << std::endl << std::endl;

    MutantStack<const char*> strStack;
    strStack.push("hello");
    strStack.push("world");
    std::cout << "top: " << strStack.top() << std::endl;
    std::cout << "pop()" << std::endl;
    strStack.pop();
    std::cout << "size: " << strStack.size() << std::endl;
    strStack.push("bye");
    strStack.push("42");
    strStack.push("testttt");

    MutantStack<const char*>::iterator str_it = strStack.begin();
    MutantStack<const char*>::iterator str_ite = strStack.end();

    std::cout << "print container : " << std::endl;
    while (str_it != str_ite)
    {
        std::cout << *str_it << std::endl;
        ++str_it;
    }
    std::stack<const char*> str(strStack);

};