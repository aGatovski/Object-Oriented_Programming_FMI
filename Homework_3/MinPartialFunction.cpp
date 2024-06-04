#include "MinPartialFunction.h"

MinPartialFunction::MinPartialFunction(const PartialFunctionCollection& _data) :MinMaxFunctionWrapper(_data)
{
}

int32_t MinPartialFunction::operator()(int32_t x) const
{
	if (!this->isDefinedAt(x)) {
		throw std::invalid_argument("Function is not defined for the given X!");
	}

	int32_t minValue = data[0](x);

    unsigned length = data.getSize();
	for (size_t i = 1; i < length; i++){
		int32_t nextValue = data[i](x);

		if (nextValue < minValue) {
			minValue = nextValue;
		}
	}

	return minValue;
}

PartialFunction* MinPartialFunction::clone() const
{
	return new MinPartialFunction(*this);
}
