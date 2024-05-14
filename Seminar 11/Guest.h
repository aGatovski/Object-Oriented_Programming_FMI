#pragma once
#include <iostream>
#include"Player.h"

class Guest :public Player{
public:
	Guest(unsigned _hoursGamePlay);

	bool levelUP() override;
private:
	unsigned hoursGamePlay = 0;
};