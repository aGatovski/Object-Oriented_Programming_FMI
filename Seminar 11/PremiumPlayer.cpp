#include "PremiumPlayer.h"


bool PremiumPlayer::levelUP()
{
	if (points > FIRST_LEVEL_UP) {
		playerStar = star2;
		points = 0;
		return true;
	}
	else if ((playerStar == star2) && points > FIRST_LEVEL_UP) {
		playerStar = star3;
		points = 0;
		return true;
	}
	else if ((playerStar == star3) && points > FIRST_LEVEL_UP) {
		playerStar = star4;
		points = 0;
		return true;
	}
	return false;
}

PremiumPlayer::PremiumPlayer(const char* _password, const char* _playerName) : LoggedPlayer(_password) {
	if (!_playerName) {
		throw ;
	}

	playerName = new char[strlen(_playerName)];
	strcpy(playerName, _playerName);
}

