#pragma once
#include<fstream>
#include "Pair.hpp"
#include "PartialFunction.h"
#include"PairFunction.h"
#include "PartialFunctionCollection.h"
#include "MinMaxFunctionWrapper.h"
#include "CriteriaFunction.hpp"
#include "MaxPartialFunction.h"
#include "MinPartialFunction.h"
#include "IdentityFunction.h"
#include "BoolFunction.h"

void readDynamicCharArrayFromBinaryFile(std::ifstream& in, char*& str);
MaxPartialFunction* createMaxFunction(std::ifstream& ifs, unsigned int N);
MinPartialFunction* createMinFunction(std::ifstream& ifs, unsigned int N);
PartialFunction* readFromFile(const char* fileName);