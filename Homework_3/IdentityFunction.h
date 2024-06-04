#pragma once
#include<iostream>
#include "Pair.hpp"
//golqma 4ka ako ne polzvash vector ookeiiii


class IdentityFunction {
private:
	int32_t* undefinedValues = nullptr;
	unsigned size = 0;
public:

	IdentityFunction(const int32_t* fileInput, size_t size);
	IdentityFunction(const IdentityFunction& other);
	IdentityFunction(IdentityFunction&& other) noexcept;
	IdentityFunction& operator=(const IdentityFunction& other);
	IdentityFunction& operator=( IdentityFunction&& other) noexcept;
	~IdentityFunction();

	bool isDefinedAt(int32_t x) const;
	Pair<bool, int32_t> operator()(int32_t x) const;

private:
	void free();
	void copyFrom(const IdentityFunction& other);
	void moveFrom(IdentityFunction&& other);
};