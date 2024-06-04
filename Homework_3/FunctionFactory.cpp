#pragma once
#include"FunctionFactory.h"

PartialFunction* readFromFile(const char* fileName)
{
    unsigned int N, T;

    std::ifstream in(fileName, std::ios::binary | std::ios::in);
    if (!in.is_open()) {
        throw std::runtime_error("Error: Unable to open file - func.dat!");
    }

    in.read((char*)&N, sizeof(N));
    in.read((char*)&T, sizeof(T));
    int arr[32]{ 0 };
    char buff[1024];

    switch (T)
    {
    case 0:
        in.read((char*)arr, (2 * N) * sizeof(int));
        return new CriteriaFunction<PairFunction>(PairFunction(arr, N));  // работи ?

        break;
    case 1:
        in.read((char*)arr, N * sizeof(int));
        return new CriteriaFunction <IdentityFunction>(IdentityFunction(arr, N));
        break;

    case 2:
        in.read((char*)arr, N * sizeof(int));
        return  new CriteriaFunction <BoolFunction>(BoolFunction(arr, N));
        break;
    case 3:
        ExtremumFunction* extremeFunctions;
         for (size_t i = 0; i < N; i++){
             in.getline(buff, 1024);
            
             PartialFunction* ptr;
             ptr = readFromFile(buff);
             extremeFunctions->addPartialFunction(ptr);
             break;
         }
         
         return new MaxPartialFunction(*extremeFunctions);
        break;
    case 4:

        for (size_t i = 0; i < N; i++) {
            in.getline(buff, 1024);
            PartialFunctionCollection temporary;
            readFromFile(buff);
            //collection.addPartialFunction(new MaxPartialFunction(temporary));
        }
        break;
    default:
        break;
    }

    in.close();
}