#include <iostream>

#include "Deck.h"
#include "Duelist.h"

char magicCardName[GlobalConstants::MAGIC_CARD_NAME_SIZE + 1] = "\0";
char magicCardEffect[GlobalConstants::MAGIC_CARD_EFF_SIZE + 1] = "\0";
Type magicCardType = unknown;

int main() {
	/*MagicCardo magicCard;
	magicCard.setMagicCardName("Justice");
	magicCard.setMagicCardEffect("PAy 155");
	magicCard.setMagicCardType(Type::trap);
	
	MagicCardo magicCard2;
	magicCard2.setMagicCardName("preve");
	magicCard2.setMagicCardEffect("add 155");
	magicCard2.setMagicCardType(Type::buff);*/

	/*MonsterCardo monsterCard1;
	monsterCard1.setAttackPoints(1000);
	monsterCard1.setDefensePoints(1000);
	monsterCard1.setMonsterCardName("Blue Eyes");

	MonsterCardo monsterCard2;
	monsterCard2.setAttackPoints(100);
	monsterCard2.setDefensePoints(100);
	monsterCard2.setMonsterCardName("red Eyes");*/

	/*Deck newDeck;
	newDeck.addMagicCard(magicCard);
	
	newDeck.addMagicCard(magicCard2);*/

	/*newDeck.printMagicCardAtIndex(0);
	newDeck.printMagicCardAtIndex(1);

	newDeck.removeMagicCard(0);
	newDeck.printMagicCardAtIndex(0);*/

	/*newDeck.swithMagicCard(magicCard2, 0);
	newDeck.printMagicCardAtIndex(0);*/

	/*Deck newDeck;
	newDeck.addMonsterCard(monsterCard1);

	newDeck.addMonsterCard(monsterCard2);

	newDeck.printMonsterCardAtIndex(0);
	newDeck.printMonsterCardAtIndex(1);

	newDeck.swithMonsterCard(monsterCard2, 0);


	newDeck.printMonsterCardAtIndex(0);
	newDeck.printMonsterCardAtIndex(1);

	newDeck.removeMonsterCard(0);
	newDeck.printMonsterCardAtIndex(0);*/

	//Deck d;

	//// 4-th card in the Monster deck becomes "Blue-eyes white dragon" with
	////ATK: 3000 DEF: 2500
	//
	//d.swithMonsterCard("Blue-eyes white dragon", 3000, 2500, 4);
	//d.swithMagicCard("Monster reborn", "revive", Type::spell, 5);


	////d.printMonsterCardAtIndex(0);
	//d.printMonsterCardAtIndex(4);


	//std::cout<<d.getMonsterCardsCount(); //1

	////Returns the amount of MonsterCards in the deck
	//std::cout << d.getMagicCardsCount(); //13

	Duelist player1("Seto Kaiba");

	///Changes the 2-nd monster card in the Monster deck to“Dark Magician”
	MonsterCardo DarkMagician("Dark Magician", 2500, 2100);
	player1.swithMonsterCard( DarkMagician,2);

	player1.printMonsterCardAtIndex(2);

	Duelist player2("Yugi Muto");

	//Changes the 2-nd magic card in the Magic deck to “Reflection”
	MagicCardo Reflection("Reflection", "Reflects the last played spell", trap);
	player2.swithMagicCard( Reflection,2);

	player2.printMagicCardAtIndex(2);
}