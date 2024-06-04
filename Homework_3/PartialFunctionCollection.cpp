#include "PartialFunctionCollection.h"
using namespace PARTIAL_FUNCTION_COLLECTION_CONSTANTS;


void PartialFunctionCollection::resize()
{
	PartialFunction** dataTemp = new PartialFunction*[capacity*=2];
	for (size_t i = 0; i < size; i++) {
		dataTemp[i] = data[i];
	}
	delete[] data;
	data = dataTemp;
}

PartialFunctionCollection::PartialFunctionCollection(): size(COLLECTION_SIZE), capacity(COLLECTION_CAPACITY) 
{
    data = new PartialFunction*[capacity];
}

PartialFunctionCollection::PartialFunctionCollection(const PartialFunctionCollection& other)
{
	copyFrom(other);
}

PartialFunctionCollection::PartialFunctionCollection(PartialFunctionCollection&& other) noexcept
{
	moveFrom(std::move(other));
}

PartialFunctionCollection& PartialFunctionCollection::operator=(const PartialFunctionCollection& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

PartialFunctionCollection& PartialFunctionCollection::operator=(PartialFunctionCollection&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

PartialFunctionCollection::~PartialFunctionCollection()
{
	free();
}

void PartialFunctionCollection::addPartialFunction(const PartialFunction& newFunction)
{
	if (size == capacity) {
		resize();
	}
	data[size++] = newFunction.clone();
}

void PartialFunctionCollection::addPartialFunction(const PartialFunction* newFunction)
{
	if (size == capacity) {
		resize();
	}
	data[size++] = newFunction->clone();
}

size_t PartialFunctionCollection::getSize() const
{
	return size;
}

PartialFunction& PartialFunctionCollection::operator[](size_t index) const
{
	return *this->data[index];
}

void PartialFunctionCollection::free()
{
	for (size_t i = 0; i < size; i++) {
		delete data[i];
	}
	delete[] data;
	data = nullptr;
}

void PartialFunctionCollection::copyFrom(const PartialFunctionCollection& other)
{
	capacity = other.capacity;
	size = other.size;
	data = new PartialFunction*[capacity];

	for (size_t i = 0; i < size; i++) {
		data[i] = other.data[i]->clone();
	}
}

void PartialFunctionCollection::moveFrom(PartialFunctionCollection&& other)
{
	data = other.data;
	capacity = other.capacity;
	size = other.size;

	other.data = nullptr;
	other.capacity = other.size = 0;
}
