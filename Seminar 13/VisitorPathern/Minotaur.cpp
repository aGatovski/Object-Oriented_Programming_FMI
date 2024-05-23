#include "Minotaur.h"

bool Minotaur::fight(const Monster& other)
{
    return other.fightMinotaur();
}

bool Minotaur::fightMinotaur() const
{
    return false;
}

bool Minotaur::fightSphinx() const
{
    return true;
}

bool Minotaur::fightCentaver() const
{
    return false;
}
