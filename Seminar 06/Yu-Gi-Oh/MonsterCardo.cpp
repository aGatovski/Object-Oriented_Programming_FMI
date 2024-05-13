#include "MonsterCardo.h"
#include <iostream>
#pragma warning (disable:4996)

MonsterCardo::MonsterCardo(const char* newMonsterCardName,const size_t newAttackPoints,const size_t newDefensePoints)
	:attackPoints(newAttackPoints) , defensePoints(newDefensePoints)  
{
	setMonsterCardName(newMonsterCardName);
	setAttackPoints(newAttackPoints);
	setDefensePoints(newDefensePoints);
}

MonsterCardo::MonsterCardo(const MonsterCardo& other) {
	copyFrom(other);
}

MonsterCardo& MonsterCardo::operator=(const MonsterCardo& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

MonsterCardo::~MonsterCardo() {
	free();
}

void MonsterCardo::copyFrom(const MonsterCardo& other) {
	unsigned cardNameLength = strlen(other.monsterCardName);
	monsterCardName = new char[cardNameLength + 1];

	strcpy(monsterCardName, other.monsterCardName);

	monsterCardName[cardNameLength + 1] = '\0';
 
	attackPoints = other.attackPoints;
	defensePoints = other.defensePoints;
}

void MonsterCardo::free() {
	monsterCardName= nullptr;
	attackPoints = 0;
	defensePoints = 0;
}

void MonsterCardo::setMonsterCardName(const char* newMonsterCardName) {
	if (!newMonsterCardName) {
		return;
	}
	unsigned cardNameLength = strlen(newMonsterCardName);
	monsterCardName = new char[cardNameLength + 1];

	strcpy(monsterCardName, newMonsterCardName);
	monsterCardName[cardNameLength + 1] = '\0';

}

void MonsterCardo::setAttackPoints(const unsigned newAttackPoints) {
	attackPoints = newAttackPoints;
}

void MonsterCardo::setDefensePoints(const unsigned newDefensePoints) {
	defensePoints = newDefensePoints;
}

const char* MonsterCardo::getMonsterCardName() const {
	return monsterCardName;
}

unsigned MonsterCardo::getATKPoints() const {
	return attackPoints;
}

unsigned MonsterCardo::getDEFPoints() const {
	return defensePoints;
}