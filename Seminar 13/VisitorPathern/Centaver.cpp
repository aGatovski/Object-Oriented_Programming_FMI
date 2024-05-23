#include "Centaver.h"


bool Centaver::fight(const Monster& other)
{
	return other.fightCentaver();
}

bool Centaver::fightMinotaur() const
{
	return 1;
}

bool Centaver::fightSphinx() const
{
	return 0;
}

bool Centaver::fightCentaver() const
{
	return 0;
}
