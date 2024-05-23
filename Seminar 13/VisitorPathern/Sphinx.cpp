#include "Sphinx.h"



bool Sphinx::fight(const Monster& other)
{
    return other.fightSphinx();
}

bool Sphinx::fightMinotaur() const
{
    return false;
}

bool Sphinx::fightSphinx() const
{
    return false;
}

bool Sphinx::fightCentaver() const
{
    return true;
}
