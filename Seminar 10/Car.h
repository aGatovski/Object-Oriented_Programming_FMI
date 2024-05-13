#include<iostream>
#include"Tire.h"
#include"Engine.h"
#include"FuelTank.h"
#include"Batery.h"


namespace CarConstants {
	constexpr double raceDistance = 0.4;
}
using namespace CarConstants;

class Car {
public:
	Car(const FuelTank& _carFuelTank, Engine* _carEngine, Tire** _carTires, Battery* _carBattery, unsigned _carKilometers, unsigned _carWeight);
	Car(const Car& other);
	Car& operator=(const Car& other);
	Car(Car&& other) noexcept;
	Car& operator=(Car&& other) noexcept;
	~Car();


	const FuelTank& getFuelTank();
	void drive(double km);

	friend Car* dragRace(Car* car1, Car* car2);
private:
	FuelTank carFuelTank;
	Engine* carEngine = nullptr;
	Tire** carTires = nullptr;
	Battery* carBattery = nullptr;
	unsigned carKilometers = 0;
	unsigned carWeight = 0;


	void free();
	void copyFrom(const Car& other);
	void moveFrom(Car&& other) noexcept;
};