#include "LoggedPlayer.h"

LoggedPlayer::LoggedPlayer(const char* _password) : Player()
{
	strcpy(password, _password);
}
bool LoggedPlayer::logIN(unsigned _ID, const char* _password) const {
	if ((_ID ==  ID)) {
		short length = strlen(_password);
		for (size_t i = 0; i < length; i++){
			if (_password[i] != password[i]) {
				return false;
			}
			return true;
		}
	}
	return false;
}