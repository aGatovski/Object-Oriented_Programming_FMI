#include "PartialFunction.h"

bool PartialFunction::isDefinedAt(int32_t x) const
{
    return false;
}

int32_t PartialFunction::operator()(int32_t x) const
{
    return 0;
}

PartialFunction* PartialFunction::clone() const
{
    return nullptr;
}
