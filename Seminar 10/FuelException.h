#pragma warning (disable:4996)
#include <iostream>
#include <exception>

class FuelException : public std::logic_error {
public:
	FuelException(const char* message, int code);
	int getCode() const;
	char const* what() const;
private:
	char message[25] = "";
	int code;
};
