#include "MultiSetClass.h"
#include <iostream>

namespace	HELP_FUNCTION {
	void swap(int& a, int& b) {
		int temp = b;
		b = a;
		a = temp;
	}

	void selectionSort(int* set, int sizeSet)
	{
		for (size_t i = 0; i < sizeSet - 1; i++) {

			
			unsigned min_idx = i;
			for (size_t j = i + 1; j < sizeSet; j++) {
				if (set[j] < set[min_idx])
					min_idx = j;
			}

			if (min_idx != i)
			swap(set[min_idx], set[i]);
		}
	}
}

using namespace HELP_FUNCTION;

void MultiSet::free() {
	n = 0;
	delete[] multiSet;
	multiSet = nullptr;
	multiSetSize = 0;
	currMultiSetIndex = 0;
}

void MultiSet::copyFrom(const MultiSet& other) {
	n = other.n;
	multiSetSize = other.multiSetSize;
	currMultiSetIndex = other.currMultiSetIndex;


	multiSet = new int[multiSetSize];

	for (size_t i = 0; i < multiSetSize; ++i) {
		multiSet[i] = other.multiSet[i];
	}
}

MultiSet::MultiSet(const unsigned n) {
	setN(n);
	setMultiSet();
}

MultiSet::MultiSet(const MultiSet& other) {
	copyFrom(other);
}

MultiSet& MultiSet::operator=(const MultiSet& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

MultiSet::~MultiSet() {
	free();
}

void MultiSet::setN(unsigned n) {
	this->n = n;
}

unsigned MultiSet::getN() const {
	return n;
}

void MultiSet::setMultiSet() {
	if (!multiSet) {
		multiSetSize = GLOBAL_CONSTANTS::MINIMAL_SET_SIZE;
		multiSet = new int[multiSetSize] {};
	}
}

void  MultiSet::addNumber(unsigned number) {
	if (number >= n) {
		std::cout << "Number out of set range!";
		return;
	}
	
	if (printCountNumberInSet(number) > 3) {
		std::cout << "Max count of " << number << " has been reached!";
		return;
	}

	if (currMultiSetIndex + 1 > multiSetSize) {
		resizeSet(GLOBAL_CONSTANTS::MINIMAL_SET_SIZE);
	}

	multiSet[currMultiSetIndex++] = number;
}

void MultiSet::resizeSet (unsigned number) {
	int* newArr = new int[multiSetSize + number];

	for (int i = 0; i < multiSetSize; ++i) {
		newArr[i] = multiSet[i];
	}

	delete[] multiSet;

	multiSet = newArr;
	multiSetSize += number;
}


unsigned MultiSet::printCountNumberInSet(int number) const {
	unsigned count = 0;

	for (size_t i = 0; i < currMultiSetIndex; i++) {
		if (multiSet[i] == number)
			count++;
		if (multiSet[i] > number)
			break;
	}
	return count;
}

void MultiSet::printSet() {
	for (size_t i = 0; i < currMultiSetIndex ; i++){
		std::cout<< multiSet[i]<<" ";
	}
}

void MultiSet::removeInstancesOfNumber(unsigned number) {
	size_t writeIndex = 0;
	for (size_t i = 0; i < currMultiSetIndex; i++) {
		if (multiSet[i] != number) {
			multiSet[writeIndex++] = multiSet[i];
		}
	}
	currMultiSetIndex = writeIndex;
}

void MultiSet::removeFirstInstanceOfANumber(unsigned number) {
	for (size_t i = 0; i < currMultiSetIndex; i++){
		if (multiSet[i] == number) {
			swap(multiSet[i], multiSet[currMultiSetIndex - 1]);
			currMultiSetIndex--;
			return;
		}
	}
}


void MultiSet::intersectSets(const MultiSet& other) { 
	int* tempSet = new int[currMultiSetIndex + other.currMultiSetIndex];
	unsigned index = 0;


	for (size_t i = 0; i < other.currMultiSetIndex; i++) {
		if (printCountNumberInSet(other.multiSet[i]) > 0) {
			tempSet[index++] = other.multiSet[i];
			removeFirstInstanceOfANumber(tempSet[index - 1]);
		}
	}

	for (size_t i = 0; i < index; i++) {
		multiSet[i] = tempSet[i];
	}

	currMultiSetIndex = index;

	delete[] tempSet;
}



void MultiSet::unionSets(const MultiSet& other) {
	
	MultiSet tempset(other);
	tempset.resizeSet(multiSetSize);

	for (size_t i = 0; i < currMultiSetIndex; i++) {
		if (tempset.printCountNumberInSet(multiSet[i]) >= 3) {
			continue;
		}
		else {
			tempset.multiSet[tempset.currMultiSetIndex++] = multiSet[i];
		}
	}

	*this = tempset;
	tempset.free();
}
