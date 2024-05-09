#include "FuelException.h"


FuelException(const char* message, int code) : code(code) {
	strcat(this->message, "[My]");
	strcat(this->message, message);
}

int getCode() const {
	return code;
}

char const* what() const {
	return message;
}
