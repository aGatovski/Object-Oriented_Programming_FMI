#include "Tire.h"
using namespace TIRE_CONSTANTS;

Tire::Tire(unsigned short _tireWidth, unsigned short _tireProfile, unsigned short _tireDiameter, const char* _manufactorerName, const char* _partDescription) : CarPart(_manufactorerName, _partDescription) {
	if (_tireWidth<MIN_WIDTH || _tireWidth>MAX_WIDTH) {
		throw std::invalid_argument("Invalid tire width!");
	}

	if (_tireProfile<MIN_PROFILE || _tireProfile>MAX_PROFILE) {
		throw std::invalid_argument("Invalid tire profile!");
	}

	if (_tireDiameter<MIN_DIAMETER || _tireDiameter>MAX_DIAMETER) {
		throw std::invalid_argument("Invalid tire diameter");
	}

	tireWidth = _tireWidth;
	tireProfile = _tireProfile;
	tireDiameter = _tireDiameter;
}
std::ostream& operator<<(std::ostream& os, const Tire& other) {
	operator<<(os, other);
	os << other.tireWidth << " / " << other.tireProfile << "R" << other.tireDiameter;
}
