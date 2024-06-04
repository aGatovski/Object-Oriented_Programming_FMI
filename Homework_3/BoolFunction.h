#pragma once
#include<iostream>
#include"Pair.hpp"

class BoolFunction {
private:
	int32_t* valuesForOne = nullptr;
	size_t size = 0;
public:
	BoolFunction(const int32_t* fileInput, size_t size);
	Pair<bool, int32_t> operator()(int32_t x) const;
};