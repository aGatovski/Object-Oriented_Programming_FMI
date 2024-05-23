#pragma once
#include "Monster.h"
#include <iostream>

class Sphinx :public Monster {
public:
	bool fight(const Monster& other);
	bool fightMinotaur()const override;
	bool fightSphinx() const override;
	bool fightCentaver() const override;
};
