#pragma once
#include <iostream>
#include "CarPart.h"

namespace TIRE_CONSTANTS {
	constexpr short MIN_WIDTH = 155;
	constexpr short MAX_WIDTH = 365;
	constexpr short MIN_PROFILE = 30;
	constexpr short MAX_PROFILE = 80;
	constexpr short MIN_DIAMETER = 13;
	constexpr short MAX_DIAMETER = 21;
}

class Tire : public CarPart {
public:
	Tire(unsigned short _tireWidth, unsigned short _tireProfile, unsigned short _tireDiameter, const char* _manufactorerName, const char* _partDescription);

	friend std::ostream& operator<<(std::ostream& os, const Tire& other);
private:
	unsigned short tireWidth = 0; // width is in milimiters between 155 and 365
	unsigned short tireProfile = 0; // profile is between 30 - 80 
	unsigned short tireDiameter = 0; // Diameter is in inches 13-21
};
