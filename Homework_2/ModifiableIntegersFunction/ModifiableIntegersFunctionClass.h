#pragma once
#include <iostream>
namespace HELPER_FUNCTIONS {
	void setFunctionValues(int16_t* functionValues, int16_t(*funcPointer)(int16_t));
}

namespace GLOBAL_CONSTANTS {
	constexpr int32_t MAX_SIZE_INT16_ARRAY = INT16_MAX * 2;
	constexpr int PRINT_LIMITS = 20;
	static int SIZE_ARRAY_REMOVED_VALUES = 8;
};

class ModifiableIntegersFunction {
private:
	int16_t (*funcPointer)(int16_t) = nullptr;
	static int16_t* functionValues;
	static int16_t* removedValues;
	int16_t removedValuesCount = 0;
public:
	ModifiableIntegersFunction() = default;
	ModifiableIntegersFunction(int16_t(*funcPointer)(int16_t));
	ModifiableIntegersFunction (const ModifiableIntegersFunction& other);
	ModifiableIntegersFunction& operator=(const ModifiableIntegersFunction& other);
	~ModifiableIntegersFunction();



	void customResultSet(int16_t input_x,int16_t output_x);
	void removeValueForX(int16_t input_x);
	
	ModifiableIntegersFunction& operator+=(const ModifiableIntegersFunction& other);
	ModifiableIntegersFunction& operator-=(const ModifiableIntegersFunction& other);
	friend ModifiableIntegersFunction operator+(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);
	friend ModifiableIntegersFunction operator-(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);


	bool operator<(const ModifiableIntegersFunction& other) const;
	bool operator<=(const ModifiableIntegersFunction& other) const;
	bool operator>(const ModifiableIntegersFunction& other) const;
	bool operator>=(const ModifiableIntegersFunction& other) const;
	
	bool isParalel(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);


	ModifiableIntegersFunction& operator^=(size_t k);
	friend ModifiableIntegersFunction operator^(const ModifiableIntegersFunction& other, size_t k);

	ModifiableIntegersFunction& operator*=(const ModifiableIntegersFunction& other);
	friend ModifiableIntegersFunction operator*(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);

	void serialize(const char* filename) const;
	void deserialize(const char* filename) const;

	void printFunction(int x1, int x2, int y1, int y2) const;

private:
	void free();
	void copyFrom(const ModifiableIntegersFunction& other);

	bool isRemoved(int16_t x)const noexcept;
	bool isInjective() const;
	bool isSurjective() const;
	bool isBijective() const;
	void resize();
};

