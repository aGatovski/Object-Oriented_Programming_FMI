#pragma once
#include <iostream>

class CarPart {
public:
	CarPart(const char* _manufactorerName, const char* _partDescription);
	CarPart(const CarPart& other);
	CarPart& operator=(const CarPart& other);
	CarPart(CarPart&& other) noexcept;
	CarPart& operator=(CarPart&& other) noexcept;
	~CarPart();

	void setManufactorerName(const char* _manufactorerName);
	const char* getManufactorerName() const;

	void setpartDescription(const char* _partDescription);
	const char* getpartDescription() const;

	friend std::ostream& operator<<(std::ostream& os, const CarPart& other);

private:
	unsigned int ID = 0;
	char* manufactorerName = nullptr;
	char* partDescription = nullptr;

	static unsigned existingParts;
	//static unsigned livingInstances;

	void free();
	void copyFrom(const CarPart& other);
	void moveFrom(CarPart&& other) noexcept;
};
