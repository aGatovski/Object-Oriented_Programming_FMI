#include "Engine.h"
Engine::Engine(unsigned short _horsePower, const char* _manufactorerName, const char* _partDescription) : CarPart(_manufactorerName, _partDescription) {
	horsePower = _horsePower;
}

std::ostream& operator<<(std::ostream& os, const Engine& other) {
	operator<<(os, other);
	os << other.horsePower << " hp";
}


unsigned short Engine::getHorsepower()const {
	return horsePower;
}
