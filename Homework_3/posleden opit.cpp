
#include"FunctionFactory.h"
#include <iostream>
namespace {
    constexpr char filename[] = "try.dat";
}
int main()
{
    PartialFunction* ptr;
    ptr = readFromFile(filename);
    std::cout<< (*ptr)(0);
}