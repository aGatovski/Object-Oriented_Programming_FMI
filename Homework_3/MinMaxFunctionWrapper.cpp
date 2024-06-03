#include "MinMaxFunctionWrapper.h"

MinMaxFunctionWrapper::MinMaxFunctionWrapper(const PartialFunctionCollection& _data) : data(_data)
{ }

bool MinMaxFunctionWrapper::isDefinedAt(int32_t x) const
{
	unsigned length = data.getSize();
	for (size_t i = 0; i < length; i++){
		if (!data[i].isDefinedAt(x)) {
			return false;
		}
	}
    return true;
}
