#pragma once
#include<fstream>
#include "Pair.hpp"
#include "PartialFunction.h"
#include"PairFunction.h"
#include "PartialFunctionCollection.h"
#include "CriteriaFunction.hpp"
#include "MaxPartialFuncion.h"
#include "MinPartialFunction.h"


namespace {
    constexpr char fileName[] = "func.dat";
}

void readFromFile(PartialFunctionCollection& collection) 
{
    unsigned N, T; 

    std::ifstream in(fileName, std::ios::binary | std::ios::in);
    if (!in.is_open()) {
        throw std::runtime_error("Error: Unable to open file - func.dat!");
    }

    in.read((char*)&N, sizeof(N));
    in.read((char*)&T, sizeof(T));


    switch (T)
    {
    case 0:
        int32_t* arr = new int32_t[N];
        in.read((char*)arr, N * sizeof(int));
        PairFunction p(arr, N);
        PartialFunction* m = new CriteriaFunction<Pair<bool,int32_t>>(m);
        collection.addPartialFunction( new CriteriaFunction<Pair<bool,int32_t>>(p));
        
        delete[] arr;
        break;
  /*  case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;*/
 /*   default:
        break;*/
    }

    in.close();
}