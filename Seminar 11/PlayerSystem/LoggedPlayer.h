#pragma once
#include "Player.h"
#include<iostream>

class LoggedPlayer : public Player
{
public:
	LoggedPlayer(const char* _password);
		
	bool logIN(unsigned _ID,const char* _password) const;
private:
	char password[8];
};

