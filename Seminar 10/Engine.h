#pragma once
#include <iostream>
#include "CarPart.h"

class Engine : public CarPart {
public:
	Engine(unsigned short _horsePower, const char* _manufactorerName, const char* _partDescription);

	unsigned short getHorsepower()const;

	friend std::ostream& operator<<(std::ostream& os, const Engine& other);

private:
	unsigned short horsePower = 0;
};