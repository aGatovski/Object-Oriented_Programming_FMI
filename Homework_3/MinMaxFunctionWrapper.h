#pragma once
#include<iostream>
#include"PartialFunction.h"
#include"PartialFunctionCollection.h"
class MinMaxFunctionWrapper : public PartialFunction{
public:
	MinMaxFunctionWrapper(const PartialFunctionCollection& _data);
	bool isDefinedAt(int32_t x) const override;


protected:

	const PartialFunctionCollection& data; 
};