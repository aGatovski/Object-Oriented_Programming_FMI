#pragma once
#include <iostream>

class MonsterCardo{
private:
	char* monsterCardName = nullptr;
	unsigned attackPoints = 0;
	unsigned defensePoints = 0;

	void copyFrom(const MonsterCardo& other);
	void free();

public:
	//default
	MonsterCardo() = default;
	//second constructor
	MonsterCardo(const char* currentMonsterCardName, const size_t currentAttackPoints, const size_t currentDefensePoiints);

	//copy constructor
	MonsterCardo(const MonsterCardo& other);
	//operator =
	MonsterCardo& operator=(const MonsterCardo& other);
	//deconstructor
	~MonsterCardo();

	void setMonsterCardName(const char* newMonsterCardName);
	
	void setAttackPoints(unsigned newATKPoints);

	void setDefensePoints(unsigned newDEFPoints);

	const char* getMonsterCardName() const;

	unsigned getATKPoints() const;

	unsigned getDEFPoints() const;
};