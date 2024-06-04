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

void readFromFile(const char* fileName, PartialFunctionCollection& collection);