#pragma once
#include"FunctionFactory.h"

PartialFunction* readFromFil(const char* fileName)
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

    PartialFunction* function;

    switch (T) 
    {
       case 0:  
            in.read((char*)arr, (2*N) * sizeof(int));    
              ( PairFunction(arr,N));  // работи ?
     
        break;
       case 1:
            in.read((char*)arr, N * sizeof(int));
            return function =  new CriteriaFunction <IdentityFunction>(IdentityFunction(arr, N));
        break;
        
    case 2:
            in.read((char*)arr, N * sizeof(int));
            return function = new CriteriaFunction <BoolFunction>(BoolFunction(arr, N));
        break;
    case 3:
        
       /* for (size_t i = 0; i < N; i++){
            in.getline(buff, 1024);
            PartialFunctionCollection temporary;
            readFromFile(buff, temporary);
            collection.addPartialFunction(new MaxPartialFunction(temporary));
            return;
        }*/
        break;
    case 4:
        
        for (size_t i = 0; i < N; i++) {
            in.getline(buff, 1024);
            PartialFunctionCollection temporary;
            readFromFile(buff, temporary);
            //collection.addPartialFunction(new MaxPartialFunction(temporary));
        }
        break;
    default:
        break;
    }

    in.close();
}