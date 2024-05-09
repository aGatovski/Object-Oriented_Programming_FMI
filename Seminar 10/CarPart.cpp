
#include "CarPart.h"
#include <exception>
unsigned CarPart::existingParts = 1;

CarPart::CarPart(const char* _manufactorerName, const char* _partDescription) {
	ID = (existingParts++);

}

CarPart::CarPart(const CarPart& other) {
	copyFrom(other);
}

CarPart& CarPart::operator=(const CarPart& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

CarPart::CarPart(CarPart&& other) noexcept {
	moveFrom(std::move(other));
}

CarPart& CarPart::operator=(CarPart&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

CarPart::~CarPart() {
	free();
}

void CarPart::setManufactorerName(const char* _manufactorerName) {
	if (!_manufactorerName) {
		throw;
	}

	manufactorerName = new char[strlen(_manufactorerName)];
	strcpy(manufactorerName, _manufactorerName);
}

const char* CarPart::getManufactorerName() const {
	return manufactorerName;
}

void CarPart::setpartDescription(const char* _partDescription) {
	if (!_partDescription) {
		throw;
	}

	partDescription = new char[strlen(_partDescription)];
	strcpy(partDescription, _partDescription);
}

const char* CarPart::getpartDescription() const {
	return partDescription;
}

void CarPart::free() {
	ID = 0;
	delete[] manufactorerName;
	manufactorerName = nullptr;
	delete[] partDescription;
	partDescription = nullptr;
}

void CarPart::copyFrom(const CarPart& other) {
	ID = other.ID;
	manufactorerName = new char[strlen(other.manufactorerName)];
	strcpy(manufactorerName, other.manufactorerName);
	partDescription = new char[strlen(other.partDescription)];
	strcpy(partDescription, other.partDescription);
}

void CarPart::moveFrom(CarPart&& other)  noexcept {
	ID = other.ID;
	manufactorerName = other.manufactorerName;
	other.manufactorerName = nullptr;

	partDescription = other.partDescription;
	other.partDescription = nullptr;
}

std::ostream& operator<<(std::ostream& os, const CarPart& other) {
	os << other.ID << " by " << other.manufactorerName << " - ";
}
