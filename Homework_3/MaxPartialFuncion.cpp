#include "MaxPartialFuncion.h"

MaxPartialFunction::MaxPartialFunction(const PartialFunctionCollection& _data) :MinMaxFunctionWrapper(_data)
{

}

int32_t MaxPartialFunction::operator()(int32_t x) const
{
	if (!this->isDefinedAt(x)) {
		throw std::invalid_argument("Function is not defined for the given X!");
	}

	int32_t maxValue = this->data[0](x);

	unsigned length = this->data.getSize();
	for (size_t i = 1; i < length; i++) {
		int32_t nextValue = this->data[i](x);

		if (nextValue > maxValue) {
			maxValue = nextValue;
		}
	}

	return maxValue;
}

PartialFunction* MaxPartialFunction::clone() const
{
	return new MaxPartialFunction(*this);
}
