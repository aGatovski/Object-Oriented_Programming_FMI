#include "CarPart.h"
#include <iostream>

class FuelTank : public CarPart{
public:
	FuelTank() = default;
	FuelTank(const char* _manufactorerName, const char* _partDescription, double _tankCapacity);
	void fill(double toFill);
	void use(double toUse);

	double getTankFuel() const ;
private:
	double tankCapacity = 0;
	double tankFuel = 0;
};



