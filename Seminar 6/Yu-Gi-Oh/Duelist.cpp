#include<iostream>
#include "Duelist.h"
#pragma warning(disable:4996)

void Duelist::free() {
	delete[]duelistName;
}
void Duelist::copyFrom(const Duelist& other) {
	unsigned duelistNameLength = strlen(other.duelistName);
	duelistName = new char[duelistNameLength];
	strcpy(duelistName, other.duelistName);

	duelistDeck = other.duelistDeck;
}

Duelist::Duelist(const Duelist& other) {
	copyFrom(other);
}

Duelist::Duelist(const char* duelistName) {
	setDuelistName(duelistName);
}

Duelist& Duelist::operator=(const Duelist& other) {

	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}
Duelist::~Duelist() {
	free();
}

void Duelist::setDuelistName(const char* newDuelistName) {
	if (!newDuelistName) {
		return;
	}

	unsigned duelistNameLength = strlen(newDuelistName);
	duelistName = new char[duelistNameLength];
	strcpy(duelistName, newDuelistName);
}
const char* Duelist::getDuelistName() const {
	return duelistName;
}


void Duelist::printMonsterCardAtIndex(unsigned index) {
	if (index<0 || index>GlobalConstants::MAX_NUMBER_MONSTER_CARDS) {
		std::cout << "No card at this index" << std::endl;
		return;
	}
	duelistDeck.printMonsterCardAtIndex(index);
}
void Duelist::printMagicCardAtIndex(unsigned index) {
	if (index<0 || index>GlobalConstants::MAX_NUMBER_MONSTER_CARDS) {
		std::cout << "No card at this index" << std::endl;
		return;
	}
	duelistDeck.printMagicCardAtIndex(index);
}

void Duelist::addMagicCard(const MagicCardo& newMagicCard) {
	duelistDeck.addMagicCard(newMagicCard);
}
void Duelist::addMonsterCard(const MonsterCardo& newMonsterCard) {
	duelistDeck.addMonsterCard(newMonsterCard);
}

void Duelist::swithMonsterCard(const MonsterCardo& newMonsterCard, unsigned indexChange) {
	duelistDeck.swithMonsterCard(newMonsterCard.getMonsterCardName(),newMonsterCard.getATKPoints(),newMonsterCard.getDEFPoints(), indexChange);
}

void Duelist::swithMagicCard(const MagicCardo& newMagicCard, unsigned indexChange) {
	duelistDeck.swithMagicCard(newMagicCard.getMagicCardName(),newMagicCard.getMagicCardEffect(),newMagicCard.getMagicCardType(), indexChange);
}


void Duelist::removeMonsterCard(unsigned indexChange) {
	duelistDeck.removeMonsterCard(indexChange);
}

void Duelist::removeMagicCard(unsigned indexChange) {
	duelistDeck.removeMagicCard(indexChange);
}