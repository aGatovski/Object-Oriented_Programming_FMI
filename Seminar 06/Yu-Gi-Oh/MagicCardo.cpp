#include "MagicCardo.h"
#include <iostream>
#pragma warning(disable:4996)


const char* MagicCardo::getMagicCardName() const {
	return magicCardName;
}

const char* MagicCardo::getMagicCardEffect() const {
	return magicCardEffect;
}

Type MagicCardo::getMagicCardType() const {
	return magicCardType;
}

void MagicCardo::setMagicCardName(const char* newMagicCardName)  {
	if (!newMagicCardName) {
		return;
	}	

	strcpy(magicCardName, newMagicCardName);	
}

void MagicCardo::setMagicCardEffect(const char* newMagicCardEffect) {
	if (!newMagicCardEffect) {
		return;
	}

	strcpy(magicCardEffect, newMagicCardEffect);
}

void MagicCardo::setMagicCardType(const Type newMagicCardType) {
	magicCardType = newMagicCardType;
}

MagicCardo::MagicCardo(const char* newMagicCardName, const char* newMagicCardEffect, Type type) {
	setMagicCardName(newMagicCardName);
	setMagicCardEffect(newMagicCardEffect);
	setMagicCardType(type);
}