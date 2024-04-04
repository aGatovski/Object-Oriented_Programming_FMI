#include "NumberSeriesClass.h"
#include <iostream>

int doubleup(int a) {
	return a * 2;
}

int main()
{

	NumSeries firstSeries(1, doubleup);
	//firstSeries.setFuncPointer(doubleup);
	//NumSeries firstSeries;
	std::cout << firstSeries.getNumberAtIndex(0);
	std::cout << firstSeries.getNumberAtIndex(1);
	std::cout << firstSeries.getNumberAtIndex(10);
	std::cout << firstSeries.getA_0()<<std::endl;

	std::cout << firstSeries.isNumberInSeries(2048);
}

