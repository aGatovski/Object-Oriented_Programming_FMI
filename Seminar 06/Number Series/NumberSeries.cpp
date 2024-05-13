#include"NumberSeriesClass.h"
#include <iostream>


namespace HELP_FUNCTIONS {
	bool binarySearch(int* numberSeries, int left, int right, int numSerch)
	{
		while (left <= right) {
			int m = left + (right - left) / 2;

			if (numberSeries[m] == numSerch)
				return true;

			if (numberSeries[m] < numSerch)
				left = m + 1;

			else
				right = m - 1;
		}

		return false;
	}
}


void NumSeries::copyFrom(const NumSeries& other) {
	a_0 = other.a_0;
	funcPointer = other.funcPointer;
	numberSeries = other.numberSeries;
}

void NumSeries::free() {
	funcPointer = nullptr;
	delete[]numberSeries;
	numberSeries = nullptr;
}

NumSeries::NumSeries(const int newa_0, int (*newFuncPointer)(int)) :a_0(newa_0) {
	
	setA_0(newa_0);
	setFuncPointer(newFuncPointer);
	setNumSeries();
}

NumSeries::NumSeries(const NumSeries& other) {
	copyFrom(other);
}

NumSeries& NumSeries::operator=(const NumSeries& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

NumSeries::~NumSeries() {
	free();
}

int NumSeries::getA_0() const {
	return a_0;
}

void NumSeries::setA_0(const int newA) {

	delete[] numberSeries;
	numberSeries = nullptr;
	//A number series does not have any restrictions for the first element it could be both positive or negative.
	a_0 = newA;
}

void NumSeries::setFuncPointer(int(*newFuncPointer)(int)) {
	if (!newFuncPointer) {
		std::cout << "Invalid function pointer!" << std::endl;
		return;
	}
	delete[] numberSeries;
	numberSeries = nullptr;

	funcPointer = newFuncPointer;
}


void  NumSeries::setNumSeries() {
	if (!numberSeries) {
		numberSeries = new int[GLOBAL_CONSTANTS::firstLengthSeries] {};
	numberSeries[seriesCount++] = a_0;
	}

	setSeriesUpToIndex(GLOBAL_CONSTANTS::firstLengthSeries);
}

void NumSeries::setSeriesUpToIndex(const unsigned index) {
	if (!numberSeries) {
		for (size_t i = 0; i <= index; i++) {
			numberSeries[seriesCount++] = getNextNumber();
		}
	}

	for (size_t i = seriesCount; i <= index; i++){
		numberSeries[seriesCount++] = getNextNumber();
	
	}
	
}

int NumSeries::getNumberAtIndex(unsigned index) {
	if (!funcPointer) {
		std::cout << "No function given!"<<std::endl;
		return 0;
	}
	if (!numberSeries) {
		std::cout << "NumberSeries not initialised!" << std::endl;
		return 0;
	}

	if (index <0) {
		std::cout << "Index out of bounds!" << std::endl;
		return 0;
	}

	if (index > seriesCount){
		setSeriesUpToIndex( seriesCount  + index);
	}

	return numberSeries[index];
}

int  NumSeries::getNextNumber() {
	return funcPointer(numberSeries[seriesCount-1]);
}

bool NumSeries::isNumberInSeries(int number) {
	while (numberSeries[seriesCount-1]<=number)
	{
		setSeriesUpToIndex(seriesCount + GLOBAL_CONSTANTS::firstLengthSeries);
	}

	return HELP_FUNCTIONS::binarySearch(numberSeries, 0, seriesCount, number);
}
