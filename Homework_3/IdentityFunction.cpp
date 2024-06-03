#include "IdentityFunction.h"

IdentityFunction::IdentityFunction(const int32_t* fileInput, size_t _size) : size(_size)
{
	undefinedValues = new int32_t[size];
	for (size_t i = 0; i < size; i++){
		undefinedValues[i] = fileInput[i];
	}
}

bool IdentityFunction::isDefinedAt(int32_t x) const
{
	for (size_t i = 0; i < size; i++){
		if (x == undefinedValues[i])
			return false;
	}
	return true;
}

Pair<bool, int32_t>  IdentityFunction::operator()(int32_t x) const
{
	if (isDefinedAt(x)) {
		return Pair<bool,int32_t>(true, x);
	}
	else {
		return Pair<bool, int32_t>(false, x);
	}
}
