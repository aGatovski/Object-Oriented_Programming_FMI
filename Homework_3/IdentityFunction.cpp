#include "IdentityFunction.h"

IdentityFunction::IdentityFunction(const int32_t* fileInput, size_t _size) : size(_size)
{
	undefinedValues = new int32_t[size];
	for (size_t i = 0; i < size; i++) {
		undefinedValues[i] = fileInput[i];
	}
}

IdentityFunction::IdentityFunction(const IdentityFunction& other)
{
	copyFrom(other);
}

IdentityFunction::IdentityFunction(IdentityFunction&& other) noexcept
{
	moveFrom(std::move(other));
}

IdentityFunction& IdentityFunction::operator=(const IdentityFunction& other)
{
	if (this != &other) {
		free();
		copyFrom(other);

	}
	return *this;
}

IdentityFunction& IdentityFunction::operator=(IdentityFunction&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));

	}
	return *this;
}

IdentityFunction::~IdentityFunction()
{
	free();
}

bool IdentityFunction::isDefinedAt(int32_t x) const
{
	for (size_t i = 0; i < size; i++) {
		if (x == undefinedValues[i])
			return false;
	}
	return true;
}

Pair<bool, int32_t>  IdentityFunction::operator()(int32_t x) const
{
	if (isDefinedAt(x)) {
		return Pair<bool, int32_t>(true, x);
	}
	else {
		return Pair<bool, int32_t>(false, x);
	}
}

void IdentityFunction::free()
{
	delete[] undefinedValues;
	 undefinedValues = nullptr;
	 size = 0;
}

void IdentityFunction::copyFrom(const IdentityFunction& other)
{
	size = other.size;
	undefinedValues = new int32_t[size];
	for (size_t i = 0; i < size; i++)
	{
		undefinedValues[i] = other.undefinedValues[i];
	}
}

void IdentityFunction::moveFrom(IdentityFunction&& other)
{
	undefinedValues = other.undefinedValues;
	other.undefinedValues = nullptr;
	size = other.size;
	other.size = 0;
}
