#pragma once
#include<iostream>
#include"PartialFunction.h"
#include"Pair.hpp"

class PairFunction  {
private:
	int32_t* pairFunctionDefinedPar = nullptr;
	int32_t* pairFunctionValues = nullptr;
	size_t size = 0;
	


public:
	bool isDefinedAt(int32_t x) const;

	PairFunction(const int32_t* fileInput, size_t size);
	Pair<bool,int32_t> operator()(int32_t x) const;
};