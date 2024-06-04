//#include "ExtremumFunction.h"
//
//using namespace PARTIAL_FUNCTION_COLLECTION_CONSTANTS;
//
//
//void ExtremumFunction::resize()
//{
//	PartialFunction** dataTemp = new PartialFunction * [capacity *= 2];
//	for (size_t i = 0; i < size; i++) {
//		dataTemp[i] = data[i];
//	}
//	delete[] data;
//	data = dataTemp;
//}
//
//ExtremumFunction::ExtremumFunction() : size(COLLECTION_SIZE), capacity(COLLECTION_CAPACITY)
//{
//	data = new PartialFunction * [capacity];
//}
//
//ExtremumFunction::ExtremumFunction(const ExtremumFunction& other)
//{
//	copyFrom(other);
//}
//
//ExtremumFunction::ExtremumFunction(ExtremumFunction&& other) noexcept
//{
//	moveFrom(std::move(other));
//}
//
//ExtremumFunction& ExtremumFunction::operator=(const ExtremumFunction& other)
//{
//	if (this != &other) {
//		free();
//		copyFrom(other);
//	}
//	return *this;
//}
//
//ExtremumFunction& ExtremumFunction::operator=(ExtremumFunction&& other) noexcept
//{
//	if (this != &other) {
//		free();
//		moveFrom(std::move(other));
//	}
//	return *this;
//}
//
//ExtremumFunction::~ExtremumFunction()
//{
//	free();
//}
//
//void ExtremumFunction::addPartialFunction(const PartialFunction& newFunction)
//{
//	if (size == capacity) {
//		resize();
//	}
//	data[size++] = newFunction.clone();
//}
//
//void ExtremumFunction::addPartialFunction(const PartialFunction* newFunction)
//{
//	if (size == capacity) {
//		resize();
//	}
//	data[size++] = newFunction->clone();
//}
//
//size_t ExtremumFunction::getSize() const
//{
//	return size;
//}
//
//PartialFunction& ExtremumFunction::operator[](size_t index) const
//{
//	return *this->data[index];
//}
//
//void ExtremumFunction::free()
//{
//	for (size_t i = 0; i < size; i++) {
//		delete data[i];
//	}
//	delete[] data;
//	data = nullptr;
//}
//
//void ExtremumFunction::copyFrom(const ExtremumFunction& other)
//{
//	capacity = other.capacity;
//	size = other.size;
//	data = new PartialFunction * [capacity];
//
//	for (size_t i = 0; i < size; i++) {
//		data[i] = other.data[i]->clone();
//	}
//}
//
//void ExtremumFunction::moveFrom(ExtremumFunction&& other)
//{
//	data = other.data;
//	capacity = other.capacity;
//	size = other.size;
//
//	other.data = nullptr;
//	other.capacity = other.size = 0;
//}
//
//
//bool ExtremumFunction::isDefinedAt(int32_t x) const
//{
//	for (size_t i = 0; i < size; i++) {
//		if (!(data[i]->isDefinedAt(x))) {
//			return false;
//		}
//	}
//	return true;
//}