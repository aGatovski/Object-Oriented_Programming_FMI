#include "Guest.h"

Guest::Guest(unsigned _hoursGamePlay) : Player(), hoursGamePlay(_hoursGamePlay) { }

bool Guest::levelUP() {
	return false;
}
