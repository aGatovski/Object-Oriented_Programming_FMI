#pragma once
#include <iostream>
#include"PartialFunction.h"

namespace PARTIAL_FUNCTION_COLLECTION_CONSTANTS
{
	constexpr unsigned COLLECTION_SIZE = 0;
	constexpr unsigned COLLECTION_CAPACITY = 4;
}

class PartialFunctionCollection {
private:
	PartialFunction** data = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	void resize();
public:
	PartialFunctionCollection();
	PartialFunctionCollection(const PartialFunctionCollection& other);
	PartialFunctionCollection(PartialFunctionCollection&& other) noexcept;
	PartialFunctionCollection& operator=(const PartialFunctionCollection& other);
	PartialFunctionCollection& operator=(PartialFunctionCollection&& other) noexcept;
	~PartialFunctionCollection();


	void addPartialFunction(const PartialFunction& newFunction);
	void addPartialFunction(const PartialFunction* newFunction);
	size_t getSize() const;
	PartialFunction& operator[](size_t index) const;
private:
	void free();
	void copyFrom(const PartialFunctionCollection& other);
	void moveFrom(PartialFunctionCollection&& other);
};