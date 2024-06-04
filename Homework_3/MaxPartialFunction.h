#pragma once
#include<iostream>
#include"ExtremumFunction.h"

class MaxPartialFunction : public ExtremumFunction {
public:
	MaxPartialFunction(const ExtremumFunction& _data);
	int32_t operator()(int32_t x) const override;
	PartialFunction* clone() const override;
};