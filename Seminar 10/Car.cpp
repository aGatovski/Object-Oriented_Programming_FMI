#include "Car.h"

Car::Car(const FuelTank& _carFuelTank, Engine* _carEngine, Tire** _carTires, Battery* _carBattery, 
	unsigned _carKilometers, unsigned _carWeight): FuelTank(_carFuelTank){//prenasochi pointerite ot lista
	if (_carKilometers < 0 || _carWeight < 0) {
		throw std::invalid_argument("Kilometers and weight must be non-negative.");
	}
	for (size_t i = 0; i < 4; i++){
		carTires[i] = _carTires[i];
	}
	carKilometers = _carKilometers;
	carWeight = _carWeight;
}

Car::Car(const Car& other){
	copyFrom(other);
}

Car& Car::operator=(const Car& other){
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Car::Car(Car&& other) noexcept{
	moveFrom(std::move(other));
}

Car& Car::operator=(Car&& other) noexcept{
	if (this != other) {
		carFuelTank = std::move(other.carFuelTank);
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Car::~Car(){
	free();
}

void Car::free(){
	carEngine = nullptr;
	carTires = nullptr;
	carBattery = nullptr;
	 carKilometers = 0;
	 carWeight = 0;
}

const FuelTank& Car::getFuelTank() const {
	return carFuelTank;
}

void Car::drive(double km) {
	if (carFuelTank.getTankFuel() >= km) {
		carKilometers += km;
		carFuelTank.use(km);
	}
}

Car* Car::dragRace(Car* car1, Car* car2) {
	if ((*car1).getFuelTank().getFuelLevel() < raceDistance && car2->getFuelTank().getFuelLevel() < raceDistance) {
		return nullptr;
	}

	if (car1->getFuelTank().getFuelLevel() < raceDistance) {
		return car2; 
	}

	if (car2->getFuelTank().getFuelLevel() < raceDistance) {
		return car1;
	}


	double ratio1 = (double)(car1->carWeight) / car1->carEngine.getHorsepower());
	double ratio2 = (double)(car2->carWeight) / car2->carEngine.getHorsepower());

	if (ratio1 < ratio2) {
		return car1;
	}
	else {
		return car2;
	}
}


void Car::copyFrom(const Car& other){
	carFuelTank = other.carFuelTank;
	carEngine = other.carEngine;
	carTires = other.carTires;
	carBattery = other.carBattery;
	carKilometers = other.carKilometers;
	carWeight = other.carWeight;
}

void Car::moveFrom(Car&& other) noexcept{
	carEngine = other.carEngine;
	carTires = other.carTires;
	carBattery = other.carBattery;
	carKilometers = other.carKilometers;
	carWeight = other.carWeight;

	other.carEngine = nullptr;
	other.carTires = nullptr;
	other.carBattery = nullptr;
}