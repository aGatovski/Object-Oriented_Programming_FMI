#pragma once
#include"FunctionFactory.h"

void readDynamicCharArrayFromBinaryFile(std::ifstream& in, char*& str) {
    size_t nameLength;
    in.read((char*)&nameLength, sizeof(nameLength));
    str = new char[nameLength + 1];
    in.read((char*)str, nameLength);
    str[nameLength] = '\0';
}

MaxPartialFunction* createMaxFunction(std::ifstream& ifs,unsigned int N) {

    PartialFunctionCollection extremeFunctions ;
    char* buff = nullptr;
   
    for (size_t i = 0; i < N; i++) {
      
        readDynamicCharArrayFromBinaryFile(ifs, buff);
        PartialFunction* ptr;
        ptr = readFromFile(buff);
        extremeFunctions.addPartialFunction(ptr);
        
    }
    delete[] buff;
    buff = nullptr;
    return new MaxPartialFunction(extremeFunctions);
}

MinPartialFunction* createMinFunction(std::ifstream& ifs, unsigned int N) {

    PartialFunctionCollection extremeFunctions;
    char* buff = nullptr;

    for (size_t i = 0; i < N; i++) {

        readDynamicCharArrayFromBinaryFile(ifs, buff);
        PartialFunction* ptr;
        ptr = readFromFile(buff);
        extremeFunctions.addPartialFunction(ptr);

    }
    delete[] buff;
    buff = nullptr; 
    return new MinPartialFunction(extremeFunctions);
}

PartialFunction* readFromFile(const char* fileName)
{
    uint16_t N, T;

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
        in.read((char*)arr, (2 * N) * sizeof(int));
        return new CriteriaFunction<PairFunction>(PairFunction(arr, N));  // работи ?
    case 1:
        in.read((char*)arr, N * sizeof(int));
        return new CriteriaFunction <IdentityFunction>(IdentityFunction(arr, N));
    case 2:
        in.read((char*)arr, N * sizeof(int));
        return  new CriteriaFunction <BoolFunction>(BoolFunction(arr, N));
    case 3:
         return createMaxFunction(in,N);
    case 4:
        return createMinFunction(in, N);
    default:
        break;
    }

    in.close();
}