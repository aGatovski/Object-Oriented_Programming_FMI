#include "ModifiableIntegersFunctionClass.h"
#include <exception>
#include <iostream>
#include <fstream>

//initialise functionValues
int16_t* ModifiableIntegersFunction::functionValues = new int16_t[GLOBAL_CONSTANTS::MAX_SIZE_INT16_ARRAY]{ 0 }; 
int16_t* ModifiableIntegersFunction::removedValues = new int16_t[GLOBAL_CONSTANTS::SIZE_ARRAY_REMOVED_VALUES]{ 0 };

void HELPER_FUNCTIONS::setFunctionValues(int16_t* functionValues, int16_t(*funcPointer)(int16_t)){
	for (int i = 0, j=0; i < GLOBAL_CONSTANTS::MAX_SIZE_INT16_ARRAY; i++,j++){
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

ModifiableIntegersFunction::ModifiableIntegersFunction(const ModifiableIntegersFunction& other) {
	copyFrom(other);
}

ModifiableIntegersFunction& ModifiableIntegersFunction::operator=(const ModifiableIntegersFunction& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

ModifiableIntegersFunction::~ModifiableIntegersFunction() {
	free();
}

void ModifiableIntegersFunction::customResultSet(int16_t input_x, int16_t output_x){
	if (input_x > INT16_MAX || input_x < (-INT16_MAX)) {
		throw std::out_of_range("The value you are trying to customize is invalid!");
	}

	if (output_x > INT16_MAX || output_x < INT16_MIN)) {
		throw std::out_of_range("The value you are trying to customize is invalid!");
	}

	if (isRemoved(input_x)) {
		throw std::logic_error("The value you are trying to customize has been removed!");
	}

	

	functionValues[input_x + INT16_MAX] = output_x;
}

void ModifiableIntegersFunction::removeValueForX(int16_t x){// -32000
	if (x > INT16_MAX || x<INT16_MIN) {
		throw std::out_of_range("The value you are trying to remove is invalid!");
	}
	if (removedValuesCount + 1 == GLOBAL_CONSTANTS::SIZE_ARRAY_REMOVED_VALUES) {
		resize();
	}

	removedValues[removedValuesCount++] = x;
	functionValues[x + INT16_MAX] = INT16_MIN;
}

ModifiableIntegersFunction& ModifiableIntegersFunction::operator+=(const ModifiableIntegersFunction& other) {
	for (int i = 0; i < other.removedValuesCount; i++){
		if (!isRemoved(other.removedValues[i])) {
			removeValueForX(other.removedValues[i]);
		}
	}

	for (int i = 0; i < GLOBAL_CONSTANTS::MAX_SIZE_INT16_ARRAY; i++){
		if (!isRemoved(i + (-INT16_MAX))) {
			functionValues[i] += other.functionValues[i];
		}
	}
	return *this;
}

ModifiableIntegersFunction& ModifiableIntegersFunction::operator-=(const ModifiableIntegersFunction& other) {
	for (int i = 0; i < other.removedValuesCount; i++){
		if (!isRemoved(other.removedValues[i])) {
			removeValueForX(other.removedValues[i]);
		}
	}

	for (int i = 0; i < GLOBAL_CONSTANTS::MAX_SIZE_INT16_ARRAY; i++) {
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

bool ModifiableIntegersFunction::isParalel(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs){
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

ModifiableIntegersFunction& ModifiableIntegersFunction::operator^=(size_t k) {
	for (size_t i = 0; i < GLOBAL_CONSTANTS::MAX_SIZE_INT16_ARRAY; i++){
		if (!isRemoved(functionValues[i])) {
			for (size_t i = 0; i < k; i++) {
				functionValues[i] = funcPointer(functionValues[i]);
			}
		}
	}
	return *this;
}

ModifiableIntegersFunction operator^(const ModifiableIntegersFunction& other, size_t k) {
	ModifiableIntegersFunction result(other);
	result ^= k;
	return result;
}

//Composition
ModifiableIntegersFunction& ModifiableIntegersFunction::operator*=(const ModifiableIntegersFunction& other) {
	for (size_t i = 0; i < other.removedValuesCount; i++){
		if (!isRemoved(other.removedValues[i])) {
			removeValueForX(other.removedValues[i]);
		}
	}

	for (size_t i = 0; i < GLOBAL_CONSTANTS::MAX_SIZE_INT16_ARRAY; i++){
		if (!isRemoved(functionValues[i])) {
			other.functionValues[i] = funcPointer(other.functionValues[i]);
			functionValues[i] = other.functionValues[i];
		}
	}
	return *this;
}

ModifiableIntegersFunction operator*(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs) {
	ModifiableIntegersFunction result(lhs);
	result *= rhs;
	return result;
}

void ModifiableIntegersFunction::serialize(const char* filename) const {
	if (!filename) {
		throw std::invalid_argument("Filename cannot be nullptr.");
	}

	std::ofstream out(filename, std::ios::binary | std::ios::out);
	if (!out.is_open()) {
		throw std::runtime_error("Failed to open file for writing.");
	}

	out.write((const char*)funcPointer, sizeof(funcPointer));
	out.write((const char*)removedValuesCount, sizeof(removedValuesCount));

	for (size_t i = 0; i < removedValuesCount; i++){
		out.write((const char*)removedValues[i], sizeof(int16_t));
	}

	for (int i = 0; i < GLOBAL_CONSTANTS::MAX_SIZE_INT16_ARRAY; i++){
		out.write((const char*)functionValues[i], sizeof(int16_t));
	}
	out.close();
}

void ModifiableIntegersFunction::deserialize(const char* filename) const {
	if (!filename) {
		throw std::invalid_argument("Filename cannot be nullptr.");
	}

	std::ifstream in(filename, std::ios::binary | std::ios::in);
	if (!in.is_open()) {
		throw std::runtime_error("Failed to open file for writing.");
	}
	in.read(( char*)funcPointer, sizeof(funcPointer));
	in.read(( char*)removedValuesCount, sizeof(removedValuesCount));

	for (size_t i = 0; i < removedValuesCount; i++) {
		in.read(( char*)removedValues[i], sizeof(int16_t));
	}

	for (int i = 0; i < GLOBAL_CONSTANTS::MAX_SIZE_INT16_ARRAY; i++) {
		in.read(( char*)functionValues[i], sizeof(int16_t));
	}
	in.close();
}

void ModifiableIntegersFunction::printFunction(int x1, int x2, int y1, int y2) const{
	int arrayPrint[GLOBAL_CONSTANTS::PRINT_LIMITS][GLOBAL_CONSTANTS::PRINT_LIMITS]{ 0 };

	if (x1 >= x2 || y1 >= y2) {
		throw std::invalid_argument("Invalid limits to print!");
	}

	if ((x2 - x1) != GLOBAL_CONSTANTS::PRINT_LIMITS || (y2 - y1) != GLOBAL_CONSTANTS::PRINT_LIMITS) {
		throw std::invalid_argument("Invalid limits to print!");
	}
	
	for (int i = x1; i < x2; i++){
		if (!isRemoved(i)) {
			if (functionValues[i] >= y1 && functionValues[i] <= y2) {
				arrayPrint[ i ][ functionValues[i] ] = 1;
			}
		}	
	}
	for (int i = GLOBAL_CONSTANTS::PRINT_LIMITS-1; i>=0; i--) {
		for (int j = GLOBAL_CONSTANTS::PRINT_LIMITS -1; j > 0 ; j--) {
			std::cout << arrayPrint[i][j];
		}
		std::cout << std::endl;
	}
}

void ModifiableIntegersFunction::free() {
	funcPointer = nullptr;
	delete[]functionValues;
	delete[]removedValues;
	functionValues = nullptr;
	removedValues = nullptr;
	removedValuesCount = 0;
}

void ModifiableIntegersFunction::copyFrom(const ModifiableIntegersFunction& other) {
	funcPointer = other.funcPointer;
	removedValuesCount = other.removedValuesCount;

	for (int i = 0; i < GLOBAL_CONSTANTS::MAX_SIZE_INT16_ARRAY; i++){
		functionValues[i] = other.functionValues[i];
	}

	removedValues = new int16_t[removedValuesCount];

	for (size_t i = 0; i < removedValuesCount; i++){
		removedValues[i] = other.removedValues[i];
	}
}

void ModifiableIntegersFunction::resize() {
	int16_t* copyArray = new int16_t[(GLOBAL_CONSTANTS::SIZE_ARRAY_REMOVED_VALUES *= 2)] { 0 };
	for (size_t i = 0; i < GLOBAL_CONSTANTS::SIZE_ARRAY_REMOVED_VALUES; i++)
	{
		copyArray[i] = removedValues[i];
	}
	delete[]removedValues;

	removedValues = copyArray;
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

bool ModifiableIntegersFunction::isInjective() const {
	for (int x1 = 0; x1 <= GLOBAL_CONSTANTS::MAX_SIZE_INT16_ARRAY; x1++) {
		for (int x2 = 0; x2 <= GLOBAL_CONSTANTS::MAX_SIZE_INT16_ARRAY; x2++) {
			if (x1 != x2 && functionValues[x1] == functionValues[x2] ) {
				return false; 
			}
		}
	}
	return true; // No
}

bool ModifiableIntegersFunction::isSurjective() const {
	bool outputFound;
	for (int y = 0; y <= GLOBAL_CONSTANTS::MAX_SIZE_INT16_ARRAY; y++) {
		outputFound = false;
		for (int x = 0; x <= GLOBAL_CONSTANTS::MAX_SIZE_INT16_ARRAY; x++) {
			if (functionValues[x] == y) {
				outputFound = true;
				break;
			}
		}
		if (!outputFound) {
			return false;
		}
	}
	return true; 
}

bool ModifiableIntegersFunction::isBijective() const {
	return isInjective() && isSurjective();
}
