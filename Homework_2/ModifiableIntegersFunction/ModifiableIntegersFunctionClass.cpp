#include "ModifiableIntegersFunctionClass.h"
#include <exception>
#include <iostream>
//initialise functionValues
int16_t* ModifiableIntegersFunction::functionValues = new int16_t[GLOBAL_CONSTANTS::MAX_SIZE_INT16_ARRAY]{ 0 }; 
int16_t* ModifiableIntegersFunction::removedValues = new int16_t[10]{ 0 };

void HELPER_FUNCTIONS::setFunctionValues(int16_t* functionValues, int16_t(*funcPointer)(int16_t)){
	int length = INT16_MAX * 2;
	for (int16_t i = -INT16_MAX, j=0; i < length; i++,j++){
		functionValues[j] = funcPointer(i);
	}
}

ModifiableIntegersFunction::ModifiableIntegersFunction(int16_t(*newFuncPointer)(int16_t)){
	if (!newFuncPointer) {
		throw std::invalid_argument("Function pointer cannot be nullptr");
	}
	funcPointer = newFuncPointer;
	HELPER_FUNCTIONS::setFunctionValues(functionValues, funcPointer);
}

void ModifiableIntegersFunction::customResultSet(int16_t input_x, int16_t output_x){
	if (input_x > INT16_MAX || input_x < (-INT16_MAX)) {
		throw std::out_of_range("The value you are trying to customize is invalid!");
	}
	if (isRemoved(input_x)) {
		throw std::logic_error("The value you are trying to customize has been removed!");
	}

	functionValues[input_x + INT16_MAX] = output_x;
}

void ModifiableIntegersFunction::removeValueForX(int16_t x){// -32000
	if (x > INT16_MAX || x<(-INT16_MAX)) {
		throw std::out_of_range("The value you are trying to remove is invalid!");
	}

	removedValues[removedValuesCount++] = x;
	functionValues[x + INT16_MAX] = (-INT16_MAX);
}

ModifiableIntegersFunction& ModifiableIntegersFunction::operator+=(const ModifiableIntegersFunction& other) {
	for (size_t i = 0; i < other.removedValuesCount; i++)
	{
		if (!isRemoved(other.removedValues[i])) {
			removedValues[removedValuesCount++] = other.removedValues[i];
		}
	}

	for (size_t i = 0; i < GLOBAL_CONSTANTS::MAX_SIZE_INT16_ARRAY; i++){
		if (!isRemoved(i + (-INT16_MAX))) {
			functionValues[i] += other.functionValues[i];
		}
	}
	return *this;
}

ModifiableIntegersFunction& ModifiableIntegersFunction::operator-=(const ModifiableIntegersFunction& other) {
	for (size_t i = 0; i < other.removedValuesCount; i++){
		if (!isRemoved(other.removedValues[i])) {
			removedValues[removedValuesCount++] = other.removedValues[i];
		}
	}

	for (size_t i = 0; i < GLOBAL_CONSTANTS::MAX_SIZE_INT16_ARRAY; i++) {
		if (!isRemoved(i + (-INT16_MAX))) {
			functionValues[i] -= other.functionValues[i];
		}
	}
	return *this;
}

ModifiableIntegersFunction operator+(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
	ModifiableIntegersFunction result(lhs);
	result += rhs;
	return result;
}

ModifiableIntegersFunction operator-(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
	ModifiableIntegersFunction result(lhs);
	result -= rhs;
	return result;
}

bool ModifiableIntegersFunction::operator<(const ModifiableIntegersFunction& other) const {
	for (size_t i = 0; i < GLOBAL_CONSTANTS::MAX_SIZE_INT16_ARRAY; i++){
		if (functionValues[i] >= other.functionValues[i]) {
			return false;
		}
	}

	return true;
}

bool ModifiableIntegersFunction::operator<=(const ModifiableIntegersFunction& other) const {
	for (size_t i = 0; i < GLOBAL_CONSTANTS::MAX_SIZE_INT16_ARRAY; i++) {
		if (functionValues[i] > other.functionValues[i]) {
			return false;
		}
	}

	return true;
}

bool ModifiableIntegersFunction::operator>(const ModifiableIntegersFunction& other) const {
	for (size_t i = 0; i < GLOBAL_CONSTANTS::MAX_SIZE_INT16_ARRAY; i++) {
		if (functionValues[i] <= other.functionValues[i]) {
			return false;
		}
	}

	return true;
}

bool ModifiableIntegersFunction::operator>=(const ModifiableIntegersFunction& other) const {
	for (size_t i = 0; i < GLOBAL_CONSTANTS::MAX_SIZE_INT16_ARRAY; i++) {
		if (functionValues[i] < other.functionValues[i]) {
			return false;
		}
	}

	return true;
}

bool operator||(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
	double ratio = 0.0;
	bool ratioSet = false;
	
	for (size_t i = 0; i < GLOBAL_CONSTANTS::MAX_SIZE_INT16_ARRAY; i++){
		// Skip if both components are zero
		if (lhs.functionValues[i] == 0 && rhs.functionValues[i] == 0)
		{
			continue;
		}
		// If one component is zero but the other is not, vectors are not parallel
		if (lhs.functionValues[i] == 0 || rhs.functionValues[i] == 0)
		{
			return false;
		}
		// Calculate the ratio of the current components
		double currentRatio = lhs.functionValues[i] / rhs.functionValues[i];
		// If the ratio is not set, set it. Otherwise, compare it with the current ratio
		if (!ratioSet)
		{
			ratio = currentRatio;
			ratioSet = true;
		}
		else if (std::abs(ratio - currentRatio) > 1e-6)
		{ // Use a small epsilon for floating point comparison
			// If the ratios are different, vectors are not parallel
			return false;
		}
	}

	return true;
}

bool ModifiableIntegersFunction::isRemoved(int16_t x) const noexcept {
	for (size_t i = 0; i < removedValuesCount; i++)
	{
		if (removedValues[i] == x) {
			return true;
		}
	}
	return false;
}
