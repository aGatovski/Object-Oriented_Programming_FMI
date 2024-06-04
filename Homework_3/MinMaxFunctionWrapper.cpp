#include "MinMaxFunctionWrapper.h"

MinMaxFunctionWrapper::MinMaxFunctionWrapper(const PartialFunctionCollection& _data) : data(_data)
{ }

bool MinMaxFunctionWrapper::isDefinedAt(int32_t x) const
{
	unsigned length = this->data.getSize();
	for (size_t i = 0; i < length; i++) {
		if (!(this->data[i].isDefinedAt(x))) {
			return false;
		}
	}
	return true;
}
