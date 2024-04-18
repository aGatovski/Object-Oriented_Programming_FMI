#include <iostream>
#include "MultiSet.h"


int main()
{
    MultiSet set(7,3);
    set.addNumber(0);
    set.addNumber(0);
    set.addNumber(1);
    set.addNumber(5);
    set.addNumber(5);
    set.addNumber(5);
    set.addNumber(5);
    std::cout << set.getCountOfOccurrences(5)<<std::endl;
    std::cout << set.getCountOfOccurrences(0);
    set.printNumbersInSet();
    std::cout<<std::endl;
    set.printMultiSet();


    MultiSet set2(7, 3);
    set.addNumber(0);
    set.addNumber(0);
    set.addNumber(1);
    set.addNumber(5);

   
   
}

