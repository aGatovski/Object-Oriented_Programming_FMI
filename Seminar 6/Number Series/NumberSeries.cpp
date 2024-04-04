#include"NumberSeriesClass.h"
#include <iostream>

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
	setNumSeries();
	setA_0(newa_0);
	setFuncPointer(newFuncPointer);
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

	//A number series does not have any restrictions for the first element it could be both positive or negative.
	a_0 = newA;
}

void NumSeries::setFuncPointer(int(*newFuncPointer)(int)) {
	if (!newFuncPointer) {
		return;
	}
	funcPointer = newFuncPointer;
}

void  NumSeries::setNumSeries() {
	numberSeries = new int[GLOBAL_CONSTANTS::firstLengthSeries];
	numberSeries[seriesCount++] = a_0;

	setSeriesUpToIndex(GLOBAL_CONSTANTS::firstLengthSeries);
}

void NumSeries::setSeriesUpToIndex(const unsigned index) {
	for (size_t i = 0; i <= index; i++){
		numberSeries[seriesCount] = getNextNumber();
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
		setSeriesUpToIndex(GLOBAL_CONSTANTS::firstLengthSeries  + index);
	}

	return numberSeries[index];

	/*if (index == 0) {
		return a_0;
	}
	return  numberSeries[index] = funcPointer(getNumberAtIndex(--index));*/
}

int  NumSeries::getNextNumber() {
	if (!numberSeries) {
		numberSeries = new int[GLOBAL_CONSTANTS::firstLengthSeries];
		return	numberSeries[seriesCount++] = funcPointer(a_0);
	}
	if (!funcPointer) {
		return 0;
	}

	return funcPointer(a_0);
}
