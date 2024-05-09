#pragma once
#include "CarPart.h"
#include <iostream>

class Battery : public CarPart {
public:
	Battery(unsigned short batteryCapacity, const char* ID, const char* _manufactorerName, const char* _partDescription);
	Battery(const Battery& other);
	Battery& operator=(const Battery& other);
	Battery(Battery&& other) noexcept;
	Battery& operator=(Battery&& other) noexcept;
	~Battery();

	friend std::ostream& operator<<(std::ostream& os, const Battery& other);

private:
	unsigned short batteryCapacity = 0; // amper - hours
	char* ID = nullptr;

	void free();
	void copyFrom(const Battery& other);
	void moveFrom(Battery&& other) noexcept;
};