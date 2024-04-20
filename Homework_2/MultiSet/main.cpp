#include <iostream>
#include "MultiSet.h"


int main()
{
    MultiSet set8(9, 3);
    MultiSet set9(7, 3);
    //Just a preview of how exceptions should be caught
    //----------------------------------------------------------
   
    try
    {
        MultiSet set(9, 3);
        
    }
    catch (const std::invalid_argument& ex)
    {
        std::cout << ex.what();
    }

    try
    {
        set8.addNumber(0);

    }
    catch (const std::out_of_range& ex)
    {
        std::cout << ex.what();
    }
    catch (const std::runtime_error& ex)
    {
        std::cout << ex.what();
    }

    try
    {
        MultiSet set10 = intersect(set8, set9);

    }
    catch (const std::logic_error& ex)
    {
        std::cout << ex.what();
    }

    try
    {
        MultiSet set10 = difference(set8, set9);

    }
    catch (const std::logic_error& ex)
    {
        std::cout << ex.what();
    }

    try
    {
        MultiSet set10 = unify(set8, set9);

    }
    catch (const std::logic_error& ex)
    {
        std::cout << ex.what();
    }

    try
    {
        set8.serialise("nqkude");

    }
    catch (const std::invalid_argument& ex)
    {
        std::cout << ex.what();
    }
    catch (const std::runtime_error& ex)
    {
        std::cout << ex.what();
    }

    try
    {
        set8.deserialise("nqkude");

    }
    catch (const std::invalid_argument& ex)
    {
        std::cout << ex.what();
    }
    catch (const std::runtime_error& ex)
    {
        std::cout << ex.what();
    }

    //Implementation
    //-----------------------------------
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

