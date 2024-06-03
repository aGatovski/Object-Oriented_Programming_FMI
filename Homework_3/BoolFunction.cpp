#include "BoolFunction.h"

BoolFunction::BoolFunction(const int32_t* fileInput, size_t size)
{
	valuesForOne = new int32_t[size];
	for (size_t i = 0; i < size; i++) {
		valuesForOne[i] = fileInput[i];
	}
}

Pair<bool, int32_t> BoolFunction::operator()(int32_t x) const
{
	for (size_t i = 0; i < size; i++){
		if (x == valuesForOne[i]) {
			return Pair<bool, int32_t>(true, 1);
		}
	}
    return Pair<bool, int32_t>(true,0);
}
