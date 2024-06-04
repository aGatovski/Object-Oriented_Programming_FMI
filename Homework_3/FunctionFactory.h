#pragma once
#include<fstream>
#include "Pair.hpp"
#include "PartialFunction.h"
#include"PairFunction.h"
#include "PartialFunctionCollection.h"
#include "CriteriaFunction.hpp"
#include "MaxPartialFunction.h"
#include "MinPartialFunction.h"
#include "IdentityFunction.h"
#include "BoolFunction.h"
#include "ExtremumFunction.h"
PartialFunction* readFromFile(const char* fileName);