#pragma once
#include <iostream>
namespace HELPER_FUNCTIONS {
	void setFunctionValues(int16_t* functionValues, int16_t(*funcPointer)(int16_t));
};

namespace GLOBAL_CONSTANTS {
	constexpr int32_t MAX_SIZE_INT16_ARRAY = INT16_MAX * 2;
};

class ModifiableIntegersFunction {
private:
	int16_t (*funcPointer)(int16_t) = nullptr;
	static int16_t* functionValues;
	static int16_t* removedValues;
	int16_t removedValuesCount = 0;
public:
	ModifiableIntegersFunction(int16_t(*funcPointer)(int16_t));
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
	
	friend bool operator||(const ModifiableIntegersFunction& lhs,const ModifiableIntegersFunction& rhs);

	ModifiableIntegersFunction& operator^=(size_t k);
	friend ModifiableIntegersFunction operator^(const ModifiableIntegersFunction& other, size_t k);

	ModifiableIntegersFunction& operator*=(const ModifiableIntegersFunction& other);
	friend ModifiableIntegersFunction operator*(const ModifiableIntegersFunction& lhs, const ModifiableIntegersFunction& rhs);

private:
	bool isRemoved(int16_t x)const noexcept;
};

