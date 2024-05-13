#pragma once

#pragma once
#include <iostream>

namespace GlobalConstants{
	constexpr unsigned MAGIC_CARD_NAME_SIZE = 25;
	constexpr unsigned MAGIC_CARD_EFF_SIZE = 100;
}

enum Type {
	trap,
	buff, 
	spell,
	unknown
};

class MagicCardo {
private:
	char magicCardName[GlobalConstants::MAGIC_CARD_NAME_SIZE + 1] = "\0";
	char magicCardEffect[GlobalConstants::MAGIC_CARD_EFF_SIZE + 1] = "\0";
	Type magicCardType = unknown;

public:

	MagicCardo() = default;

	MagicCardo(const char* newMagicCardName, const char* newMagicCardEffect, Type type);

	void setMagicCardName(const char* newMagicCardName);

	void setMagicCardEffect(const char* newMagicCardEffect);

	void setMagicCardType(const Type newMagicCardType);

	const char* getMagicCardName() const;

	const char* getMagicCardEffect() const;

	Type getMagicCardType() const;
};