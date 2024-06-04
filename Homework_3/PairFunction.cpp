#include "PairFunction.h"


//ако кажат разписваш ис дефайнд да нямаш ф

PairFunction::PairFunction(const int32_t* fileInput, size_t _size) :size(_size)
{
	pairFunctionDefinedPar = new int32_t[size];
	pairFunctionValues = new int32_t[size];

	for (size_t i = 0; i < size; i++){
		pairFunctionDefinedPar[i] = fileInput[i];
		pairFunctionValues[i] = fileInput[i + size];
	}
}

PairFunction::PairFunction(const PairFunction& other)
{
	copyFrom(other);
}

PairFunction::PairFunction(PairFunction&& other) noexcept
{
	moveFrom(std::move(other));
}

PairFunction& PairFunction::operator=(const PairFunction& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

PairFunction& PairFunction::operator=(PairFunction&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

PairFunction::~PairFunction()
{
	free();
}

Pair<bool, int32_t> PairFunction::operator()(int32_t x) const
{
	for (size_t i = 0; i < size; i++){
		if (x == pairFunctionDefinedPar[i]) {
			return Pair<bool, int32_t>(true,pairFunctionValues[i]);
		}
	}
	return Pair<bool, int32_t>(false,x);
}

void PairFunction::free()
{
	delete[] pairFunctionValues;
	pairFunctionValues = nullptr;
	delete[] pairFunctionDefinedPar;
	pairFunctionDefinedPar = nullptr;
}

void PairFunction::copyFrom(const PairFunction& other)
{
	size = other.size;
	pairFunctionDefinedPar = new int32_t[size];
	pairFunctionValues = new int32_t[size];
	for (size_t i = 0; i < size; i++) {
		pairFunctionDefinedPar[i] = other.pairFunctionDefinedPar[i];
		pairFunctionValues[i] = other.pairFunctionValues[i];
	}
}

void PairFunction::moveFrom(PairFunction&& other)
{
	size = other.size; 
	pairFunctionDefinedPar = other.pairFunctionDefinedPar;
	pairFunctionValues = other.pairFunctionValues;

	other.pairFunctionValues = other.pairFunctionDefinedPar = nullptr;
	other.size = 0;
}
