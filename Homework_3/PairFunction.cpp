#include "PairFunction.h"


//ако кажат разписваш ис дефайнд да нямаш ф

PairFunction::PairFunction(const int32_t* fileInput, size_t _size) :size(_size/2)
{
	for (size_t i = 0; i < size; i++){
		pairFunctionDefinedPar[i] = fileInput[i];
		pairFunctionValues[i] = fileInput[i + size]; // + - 1 proveri
	}
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
