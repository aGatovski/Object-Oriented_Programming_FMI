#pragma once
#include<iostream>
#include"Deck.h"

class Duelist {
private:
	char* duelistName = nullptr;
	Deck duelistDeck;

	void free();
	void copyFrom(const Duelist& other);
public:
	Duelist() = default;
	Duelist(const char* duelistName);
	Duelist(const Duelist& other);
	Duelist& operator=(const Duelist& other);
	~Duelist();

	void setDuelistName(const char* newDuelistName);
	const char* getDuelistName() const;


	void printMonsterCardAtIndex(unsigned index);
	void printMagicCardAtIndex(unsigned index);

	void addMagicCard(const MagicCardo& newMagicCard);
	void addMonsterCard(const MonsterCardo& newMonsterCard);

	void swithMonsterCard(const MonsterCardo& newMonsterCard, unsigned indexChange);
	void swithMagicCard(const MagicCardo& newMagicCard, unsigned indexChange);

	void removeMonsterCard(unsigned indexChange);
	void removeMagicCard(unsigned indexChange);
};