#pragma once
#pragma warning (disable:4996)
#include<iostream>

namespace PLAYER_CONSTANTS {
	constexpr short FIRST_LEVEL_UP = 256;
	constexpr short SECOND_LEVEL_UP = 512;
	constexpr short THIRD_LEVEL_UP = 1024;
	constexpr short FORTH_LEVEL_UP = 2048;
	
}
using namespace PLAYER_CONSTANTS;

enum  Stars : bool {
	star1 = 1,
	star2 = 2,
	star3 = 3,
	star4 = 4,
	star5 = 5
};


class Player {
public:
	Player(); 
	virtual bool levelUP();

protected:
	int ID = 0;
	size_t points= 0 ;
	Stars playerStar = star1;


	static unsigned existingPlayers;
};