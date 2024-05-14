#include "LoggedPlayer.h"
#include<iostream>
#pragma once

class PremiumPlayer :public LoggedPlayer {
public:
	PremiumPlayer(const char* _password,const char* _playerName);
	bool levelUP() override;
private:
	char* playerName = nullptr;
};
