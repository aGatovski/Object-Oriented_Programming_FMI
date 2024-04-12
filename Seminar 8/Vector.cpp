#include "Vector.h"
using namespace HELPER_FUNCTIONS;

void Vector::copyFrom(const Vector& other) {
	arraySize = other.arraySize;
	arrayMaxCapacity = other.arrayMaxCapacity;

	array = new int[arrayMaxCapacity];

	for (size_t i = 0; i < arraySize; i++)
	{
		array[i] = other.array[i];
	}
}

void Vector::free() {
	delete[] array;
	array = nullptr;
	arraySize = 0;
	arrayMaxCapacity = 0;
}

//
Vector::Vector() {
	arrayMaxCapacity = getNextPowerOf2(1);
	arraySize = 0;
	array = new int[arrayMaxCapacity];
}

// v nachaloto ako mu dam samo size pravi prazen
Vector::Vector(unsigned newSize): arraySize(newSize) {
	arrayMaxCapacity = getNextPowerOf2(newSize);
	array = new int[arrayMaxCapacity] { 0 };
}

// v nachaloto ako mu dam moq masiv i lengtha mu
Vector::Vector(const int* newVector, unsigned newArraySize) : arraySize(newArraySize) {
	arrayMaxCapacity = getNextPowerOf2(newArraySize);
	array = new int[arrayMaxCapacity];

	for (size_t i = 0; i < newArraySize; i++){
		array[i] = newVector[i];
	}
}

Vector::Vector(const Vector& other) {
	copyFrom(other);
}

Vector& Vector::operator=(const Vector& other) {
if (this != &other) {
	free();
	copyFrom(other);
}
return *this;
}

Vector::~Vector() {
	free();
}
//kak shte raboti za downsize
void Vector::resize(int newCapacity) { 
	arrayMaxCapacity = newCapacity; 
	int* copyArray = new int[arrayMaxCapacity] { 0 };
	for (size_t i = 0; i < arraySize; i++)
	{
		copyArray[i] = array[i];
	}
	delete[]array;

	array = copyArray;
}

void Vector::pushBack(int number) {
	if (arraySize + 1 > arrayMaxCapacity) {
		resize(getNextPowerOf2(arraySize));
	}
	
	array[arraySize++] = number;
}

