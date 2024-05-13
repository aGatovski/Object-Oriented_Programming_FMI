#pragma once

namespace HELPER_FUNCTIONS {
	unsigned int getNextPowerOf2(unsigned number) {
		unsigned int power = 1;
		while (power < number) {
			power <<= 1;
		}
		return power;
	}
}

class Vector {
private:
	int* array = nullptr;
	unsigned arraySize = 0;
	unsigned arrayMaxCapacity = 0; //power of 2
	
public:
	Vector();
	Vector(unsigned newArraySize);
	Vector(const int* newVector, unsigned newArraySize);
	Vector(const Vector& other);
	Vector& operator=(const Vector& other);
	~Vector();

	void resize(int newCapacity);
	void pushBack(int number);
	void popBack(int number);
private:
	void copyFrom(const Vector& other);
	void free();

};
