#pragma once

class Monster {
public:
	virtual bool fight(const Monster& other);
	virtual bool fightMinotaur()const = 0;
	virtual bool fightSphinx() const = 0;
	virtual bool fightCentaver() const = 0;
private:

};