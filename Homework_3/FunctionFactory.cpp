#pragma once
#include<fstream>
#include "Pair.hpp"
#include "PartialFunction.h"
#include"PairFunction.h"
#include "PartialFunctionCollection.h"
#include "CriteriaFunction.hpp"
#include "MaxPartialFuncion.h"
#include "MinPartialFunction.h"
#include "IdentityFunction.h"
#include "BoolFunction.h"

void readFromFile(const char* fileName,PartialFunctionCollection& collection)
{
    unsigned N, T; 

    std::ifstream in(fileName, std::ios::binary | std::ios::in);
    if (!in.is_open()) {
        throw std::runtime_error("Error: Unable to open file - func.dat!");
    }

    in.read((char*)&N, sizeof(N));
    in.read((char*)&T, sizeof(T));
    int arr[32]{ 0 };

    switch (T)
    {
       case 0:  
            in.read((char*)arr, N * sizeof(int));
            collection.addPartialFunction( new CriteriaFunction<PairFunction>( PairFunction(arr,N)));
     
        break;
       case 1:
            in.read((char*)arr, N * sizeof(int));
            collection.addPartialFunction(new CriteriaFunction <IdentityFunction>(IdentityFunction(arr, N)));
        break;
        
    case 2:
            in.read((char*)arr, N * sizeof(int));
            collection.addPartialFunction(new CriteriaFunction <BoolFunction>(BoolFunction(arr, N)));
        break;
    case 3:
        char buff[1024];
        for (size_t i = 0; i < N; i++){
            in.getline(buff, 1024);
            PartialFunctionCollection temporary;
            readFromFile(buff, temporary);
            collection.addPartialFunction(new MaxPartialFunction( temporary ));
        }
        break;
    case 4:
        break;
    default:
        break;
    }

    in.close();
}