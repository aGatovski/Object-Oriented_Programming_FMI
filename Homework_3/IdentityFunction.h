#pragma once
#include<iostream>
#include "PartialFunction.h"

//golqma 4ka ako ne polzvash vector ookeiiii


class IdentityFunction :public PartialFunction {
private:
	int32_t* undefinedValues = nullptr;
	unsigned size = 0;
public:
	bool isDefinedAt(int32_t x) const override;
	int32_t operator()(int32_t x) const override;
	//PartialFunction* clone() const override;
};