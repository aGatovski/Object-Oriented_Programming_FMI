#include <iostream>
#include "MultiSet.h"


int main()
{
    MultiSet set(9,3);
    set.addNumber(0);
    set.addNumber(0);
    set.addNumber(1);
    set.addNumber(3);
    set.addNumber(5);
    set.addNumber(5);
    set.addNumber(5);
  /*  std::cout << set.getCountOfOccurrences(5)<<std::endl;
    std::cout << set.getCountOfOccurrences(0);*/
    set.printNumbersInSet();
    std::cout<<std::endl;
    set.printMultiSet();
    std::cout << std::endl;

   /* set.complete();
    set.printNumbersInSet();
    std::cout << std::endl;
    set.printMultiSet();
    std::cout << std::endl;*/


    set.serialise("purviopit");
    set.printMultiSet();
    std::cout << std::endl;


    set.addNumber(7);
    set.printMultiSet();
    std::cout << std::endl;

    set.deserialise("purviopit");
    set.printMultiSet();
    std::cout << std::endl;

    //MultiSet set2(7, 3);
    //set2.addNumber(0);
    //set2.addNumber(0);
    //set2.addNumber(1);
    //set2.addNumber(5);
    //set2.printMultiSet();
    //std::cout << std::endl;


    //MultiSet set3 = intersect(set, set2);
    //set3.printMultiSet();
    //std::cout<< std::endl;
   
    //MultiSet set4 = unify(set, set2);
    //set4.printMultiSet();

    //std::cout << std::endl;

    //MultiSet set5 = difference(set, set2);
    //set5.printMultiSet();

    //std::cout << std::endl;
}


