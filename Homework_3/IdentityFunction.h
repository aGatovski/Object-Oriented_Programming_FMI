#pragma once
#include<iostream>
#include "Pair.hpp"
//golqma 4ka ako ne polzvash vector ookeiiii


class IdentityFunction{
private:
	int32_t* undefinedValues = nullptr;
	unsigned size = 0;
public:
	IdentityFunction(const int32_t* fileInput, size_t size);
	bool isDefinedAt(int32_t x) const;
	Pair<bool,int32_t> operator()(int32_t x) const;
};