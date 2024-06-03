#pragma once
#include<iostream>
#include"MinMaxFunctionWrapper.h"

class MaxPartialFunction : public MinMaxFunctionWrapper {
public:
	int32_t operator()(int32_t x) const override;
};