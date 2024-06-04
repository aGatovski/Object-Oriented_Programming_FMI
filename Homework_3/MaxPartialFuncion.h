#pragma once
#include<iostream>
#include"MinMaxFunctionWrapper.h"

class MaxPartialFunction : public MinMaxFunctionWrapper {
public:
	MaxPartialFunction(const PartialFunctionCollection& _data);
	int32_t operator()(int32_t x) const override;
	PartialFunction* clone() const override;
};