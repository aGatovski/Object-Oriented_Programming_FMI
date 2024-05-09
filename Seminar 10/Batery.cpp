#include "Battery.h"
Battery::Battery(unsigned short _batteryCapacity, const char* _ID, const char* _manufactorerName, const char* _partDescription) : CarPart(_manufactorerName, _partDescription) {
	batteryCapacity = _batteryCapacity;
	ID = new char[strlen(_ID)];
	strcpy(ID, _ID);
}

Battery::Battery(const Battery& other) : CarPart(other) {
	copyFrom(other);
}
Battery& Battery::operator=(const Battery& other) {
	if (this != &other) {
		CarPart::operator=(other);
		free();
		copyFrom(other);
	}

	return *this;
}
Battery::Battery(Battery&& other) noexcept : CarPart(std::move(other)) {
	moveFrom(std::move(other));
}

Battery& Battery::operator=(Battery&& other) noexcept {
	if (this != &other) {
		CarPart::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Battery::~Battery() {
	free();
}


void Battery::free() {
	batteryCapacity = 0;
	delete[] ID;
	ID = nullptr;
}

void Battery::copyFrom(const Battery& other) {
	batteryCapacity = other.batteryCapacity;
	ID = new char[strlen(other.ID)];
	strcpy(ID, other.ID);
}

void Battery::moveFrom(Battery&& other) noexcept {
	batteryCapacity = other.batteryCapacity;
	batteryCapacity = 0;

	ID = other.ID;
	other.ID = nullptr;
}

std::ostream& operator<<(std::ostream& os, const Battery& other) {
	operator<<(os, other);
	os << other.batteryCapacity << "amph"
}