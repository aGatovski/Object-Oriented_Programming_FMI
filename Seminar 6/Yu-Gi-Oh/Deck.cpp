#include "Deck.h"
#include <iostream>
#pragma warning(disable:4996)


void Deck::printMonsterCardAtIndex(unsigned index) {
	if (monsterCards[index].getMonsterCardName() == nullptr) {
		std::cout << "No card at this index" << std::endl;
		return;
	}

	std::cout << "MonsterCardName " <<monsterCards[index].getMonsterCardName() << std::endl;
	std::cout << monsterCards[index].getATKPoints() << " " << monsterCards[index].getDEFPoints()<<std::endl;
}

void Deck::printMagicCardAtIndex(unsigned index) {

	
	if (magicCards[index].getMagicCardType() == Type::unknown || (index<0 || index>GlobalConstants::MAX_NUMBER_MAGIC_CARDS)) {
		std::cout << "No card at this index" << std::endl;
		return;
	}

	std::cout << "MagicCard name " << magicCards[index].getMagicCardName() << " Effect: " << magicCards[index].getMagicCardEffect() << " Type " << magicCards[index].getMagicCardType() << std::endl;
}


void Deck::setMonsterCardsCount(unsigned newMonsterCardsCount) {
	if (newMonsterCardsCount > 20)
		newMonsterCardsCount = 20;

	monsterCardsCount = newMonsterCardsCount;
}
void Deck::setMagicCardsCount(unsigned newMagicCardsCount) {
	if (newMagicCardsCount > 20)
		newMagicCardsCount = 20;


	magicCardsCount = newMagicCardsCount;
}

unsigned Deck::getMonsterCardsCount() const {
	return monsterCardsCount;
}
unsigned Deck::getMagicCardsCount() const {
	return magicCardsCount;
}
void Deck::addMagicCard(const MagicCardo& newMagicCard) {
	if (magicCardsCount == GlobalConstants::MAX_NUMBER_MAGIC_CARDS) {
		return;
	}

	magicCards[magicCardsCount++] = newMagicCard;
}
void Deck::addMonsterCard(const MonsterCardo& newMonsterCard) {
	if (monsterCardsCount == GlobalConstants::MAX_NUMBER_MONSTER_CARDS) {
		return;
	}

	monsterCards[monsterCardsCount++] = newMonsterCard;
}

void Deck::swithMonsterCard(const char* newMonsterCardName,const unsigned newMonsterCardATK,const unsigned newMonsterCardDEF, unsigned indexChange) {
	if (indexChange < 0 || indexChange > GlobalConstants::MAX_NUMBER_MONSTER_CARDS)
	{
		std::cout << "Index out of range." << std::endl;
		return;
	}
	if (!monsterCards[indexChange].getMonsterCardName()) {
		monsterCardsCount++;
	}


	monsterCards[indexChange].setMonsterCardName(newMonsterCardName);
	monsterCards[indexChange].setAttackPoints(newMonsterCardATK);
	monsterCards[indexChange].setDefensePoints(newMonsterCardDEF);
	
}

void Deck::swithMagicCard(const char* newMagicCardName, const char* newMagicCardEffect, const Type& type, unsigned indexChange) {
	if (indexChange < 0 || indexChange > GlobalConstants::MAX_NUMBER_MAGIC_CARDS)
	{
		std::cout << "Index out of range." << std::endl;
		return;
	}
	if (magicCards[indexChange].getMagicCardType() == unknown) {
		magicCardsCount++;
	}

		magicCards[indexChange].setMagicCardName(newMagicCardName);
		magicCards[indexChange].setMagicCardEffect(newMagicCardEffect);
		magicCards[indexChange].setMagicCardType(type);

	
}

void Deck::removeMonsterCard(unsigned indexChange) {
	if (indexChange < 0 || indexChange > GlobalConstants::MAX_NUMBER_MONSTER_CARDS)
	{
		return;
	}

	monsterCards[indexChange].setMonsterCardName("\0");
	monsterCards[indexChange].setAttackPoints(0);
	monsterCards[indexChange].setDefensePoints(0);
	monsterCardsCount--;
}

void Deck::removeMagicCard(unsigned indexChange) {
	if (indexChange < 0 || indexChange > GlobalConstants::MAX_NUMBER_MAGIC_CARDS)
	{
		return;
	}
	magicCards[indexChange].setMagicCardName("\0");
	magicCards[indexChange].setMagicCardEffect("\0");
	magicCards[indexChange].setMagicCardType(Type::unknown);
	magicCardsCount--;
	

}


/*Масив от карти чудовища (максимално – 20 карти).
Масив от магически карти (максимално – 20 карти).
Метод, който връща като резултат броя на магическите карти в тестето.
Метод, който връща като резултат броя на картите чудовища в тестето.

Метод, който добавя магическа карта към тестето.
Метод, който добавя карта чудовище към тестето.
Метод, който променя магическа карта от тестето, като за параметри приема индекс и нова карта.
Метод, който променя карта чудовище от тестето, като за параметри приема индекс и нова карта.
Метод, който премахва магическата карта на определена позиция от тестето
Метод, който премахва картата чудовище на определена позиция от тестето*/