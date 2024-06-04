#pragma once
#include<iostream>
#include"PartialFunction.h"
#include"Pair.hpp"

class PairFunction {
private:
	int32_t* pairFunctionDefinedPar = nullptr;
	int32_t* pairFunctionValues = nullptr;
	size_t size = 0;
public:
	PairFunction(const int32_t* fileInput, size_t size);
	PairFunction(const PairFunction& other);
	PairFunction(PairFunction&& other) noexcept;
	PairFunction& operator=(const PairFunction& other);
	PairFunction& operator=(PairFunction&& other) noexcept;
	~PairFunction();
	Pair<bool, int32_t> operator()(int32_t x) const;
private:
	void free();
	void copyFrom(const PairFunction& other);
	void moveFrom(PairFunction&& other);
};