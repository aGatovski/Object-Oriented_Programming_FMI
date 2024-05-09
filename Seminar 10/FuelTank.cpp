#include "FuelTank.h"
#include "FuelException.h"

FuelTank::FuelTank(const char* _manufactorerName, const char* _partDescription, double _tankCapacity) : CarPart(_manufactorerName, _partDescription){
	tankCapacity = _tankCapacity;
	tankFuel = _tankCapacity;
}

void FuelTank::fill(double toFill){
	if (toFill + tankFuel > tankCapacity) {
		tankFuel = tankCapacity;
		return;
	}
	tankFuel += toFill;
}

void FuelTank::use(double toUse){
	if ((tankFuel - toUse) < 0) {
		throw FuelException("insufficient_fuel_error", 1);
	}
	tankFuel -= toUse;
}

FuelTank::FuelTank() {
	return tankFuel;
}