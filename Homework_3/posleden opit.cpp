#include"UI.h"
#include"FunctionFactory.h"
#include <iostream>

int main()
{
     char filename[256];
     unsigned a, b;
     bool regime;

     std::cout << "Please enter file name: ";
     std::cin >> filename;

     std::cout << "Please enter a: ";
     std::cin >> a;

     std::cout << "Please enter b: ";
     std::cin >> b;

     std::cout << "Please enter regime (0 or 1): ";
     std::cin >> regime;

     run(filename,a, b, regime);

     return 0;
}