#pragma once
#pragma once
#pragma once
#include <iostream>
#include"PartialFunction.h"

namespace PARTIAL_FUNCTION_COLLECTION_CONSTANTS
{
	constexpr unsigned COLLECTION_SIZE = 0;
	constexpr unsigned COLLECTION_CAPACITY = 4;
}

class ExtremumFunction : public PartialFunction{
protected:
	PartialFunction** data = nullptr;
private:
	size_t size = 0;
	size_t capacity = 0;

	void resize();
public:
	ExtremumFunction();
	ExtremumFunction(const ExtremumFunction& other);
	ExtremumFunction(ExtremumFunction&& other) noexcept;
	ExtremumFunction& operator=(const ExtremumFunction& other);
	ExtremumFunction& operator=(ExtremumFunction&& other) noexcept;
	~ExtremumFunction();


	void addPartialFunction(const PartialFunction& newFunction);
	void addPartialFunction(const PartialFunction* newFunction);
	size_t getSize() const;
	PartialFunction& operator[](size_t index) const;
	bool isDefinedAt(int32_t x) const override;
private:
	void free();
	void copyFrom(const ExtremumFunction& other);
	void moveFrom(ExtremumFunction&& other);
};