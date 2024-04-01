#include "MonsterCardo.h"
#include "MagicCardo.h"
#include <iostream>
#pragma once

namespace GlobalConstants {
	constexpr unsigned MAX_NUMBER_MONSTER_CARDS = 20;
	constexpr unsigned MAX_NUMBER_MAGIC_CARDS = 20;
}


class Deck {
private:
	MonsterCardo monsterCards[GlobalConstants::MAX_NUMBER_MONSTER_CARDS] = {};
	MagicCardo magicCards[GlobalConstants::MAX_NUMBER_MAGIC_CARDS] = {};
	unsigned monsterCardsCount = 0;
	unsigned magicCardsCount = 0;

public:
	Deck() = default;

	void printMonsterCardAtIndex(unsigned index);
	void printMagicCardAtIndex(unsigned index);

	void setMonsterCardsCount(unsigned newMonsterCardsCount);
	void setMagicCardsCount(unsigned newMonsterCardsCount);

	unsigned getMonsterCardsCount() const;
	unsigned getMagicCardsCount() const;

	void addMagicCard(const MagicCardo& newMagicCard);
	void addMonsterCard(const MonsterCardo& newMonsterCard);

	void swithMonsterCard(const char* newMonsterCardName, const unsigned newMonsterCardATK, const unsigned newMonsterCardDEF, unsigned indexChange);
	void swithMagicCard(const char* newMagicCardName, const char* newMagicCardEffect, const Type& type, unsigned indexChange);

	void removeMonsterCard( unsigned indexChange);
	void removeMagicCard( unsigned indexChange);
};
