#include "BoolFunction.h"

BoolFunction::BoolFunction(const int32_t* fileInput, size_t size) : size(size)
{
	valuesForOne = new int32_t[size];
	for (size_t i = 0; i < size; i++) {
		valuesForOne[i] = fileInput[i];
	}
}

Pair<bool, int32_t> BoolFunction::operator()(int32_t x) const
{
	for (size_t i = 0; i < size; i++) {
		if (x == valuesForOne[i]) {
			return Pair<bool, int32_t>(true, 1);
		}
	}
	return Pair<bool, int32_t>(true, 0);
}

BoolFunction::BoolFunction(const BoolFunction& other)
{
	copyFrom(other);
}

BoolFunction::BoolFunction(BoolFunction&& other) noexcept
{
	moveFrom(std::move(other));
}

BoolFunction& BoolFunction::operator=(const BoolFunction& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

BoolFunction& BoolFunction::operator=(BoolFunction&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

BoolFunction::~BoolFunction()
{
	free();
}

void BoolFunction::free()
{
	delete[]valuesForOne;
	valuesForOne = nullptr;
}

void BoolFunction::copyFrom(const BoolFunction& other)
{
	size = other.size;
	valuesForOne = new int32_t[size];
	for (size_t i = 0; i < size; i++)
	{
		valuesForOne[i] = other.valuesForOne[i];
	}
}

void BoolFunction::moveFrom(BoolFunction&& other)
{
	valuesForOne = other.valuesForOne;
	other.valuesForOne = nullptr;
	size = other.size;
	other.size = 0;
	
}
