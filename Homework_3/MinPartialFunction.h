#pragma once
#include<iostream>
#include"MinMaxFunctionWrapper.h"

class MinPartialFunction : public MinMaxFunctionWrapper {
public:
	MinPartialFunction(const PartialFunctionCollection& _data);
	int32_t operator()(int32_t x) const override;
	PartialFunction* clone() const override;
};
