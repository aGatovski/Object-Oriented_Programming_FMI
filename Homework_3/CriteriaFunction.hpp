#pragma once
#include<iostream>
#include"Pair.hpp"
#include"PartialFunction.h"

template<typename F>
class CriteriaFunction : public PartialFunction {
private:
    const F& obj;
public:
    CriteriaFunction(const F& _obj);
    bool isDefinedAt(int32_t x) const override;
    int32_t operator()(int32_t x) const override; 
    PartialFunction* clone() const override;
};

template<typename F>
CriteriaFunction<F>::CriteriaFunction(const F& _obj) : obj(_obj)
{ }

template<typename F>
bool CriteriaFunction<F>::isDefinedAt(int32_t x) const
{
    return obj(x).getFirst();
}

template<typename F>
int32_t CriteriaFunction<F>::operator()(int32_t x) const
{
    if( isDefinedAt(x))
     return obj(x).getSecond();

    else {
        throw std::invalid_argument("Function is not defined for the given X!");
    }
}

template<typename F>
PartialFunction* CriteriaFunction<F>::clone() const
{
    return new CriteriaFunction(*this);
}
