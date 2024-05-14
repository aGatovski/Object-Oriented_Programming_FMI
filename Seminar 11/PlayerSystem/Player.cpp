#include "Player.h"

unsigned Player::existingPlayers = 0;

Player::Player() {
	ID = (++existingPlayers);
}

bool Player::levelUP()
{
	if (points > FIRST_LEVEL_UP) {
		playerStar = star2;
		points = 0;
		return true;
	}
	else if ((playerStar == star2) && points > SECOND_LEVEL_UP) {
		playerStar = star3;
		points = 0;
		return true;
	}
	else if ((playerStar == star3) && points > THIRD_LEVEL_UP) {
		playerStar = star4;
		points = 0;
		return true;
	}
	return false;
}
