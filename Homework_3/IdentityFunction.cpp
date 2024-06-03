#include "IdentityFunction.h"

bool IdentityFunction::isDefinedAt(int32_t x) const
{
	for (size_t i = 0; i < size; i++){
		if (x == undefinedValues[i])
			return false;
	}
	return true;
}

int32_t IdentityFunction::operator()(int32_t x) const
{
	if (isDefinedAt(x))
		return x;
	else {
		throw std::invalid_argument("The function is not defined at the given argument!");
	}
}
