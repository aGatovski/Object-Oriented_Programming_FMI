#include <iostream>

using std::strncpy;

struct Pair {
	double number;
	char ErrorCode[1024];
};

void printPair(const Pair& p) {
	std::cout << p.number << " " << p.ErrorCode;
}

size_t getStringLength(const char* text) {
	if (!text) {
		return 0;
	}

	size_t length = 0;

	while (text[length] != '\0') {
		length++;
	}

	return length;
}

void stringCopy(char* destination, const char* source) {
	if (!destination || !source) {
		return;
	}

	size_t length = getStringLength(source);

	for (size_t i = 0; i < length; i++)
	{
		destination[i] = source[i];
	}

	destination[length] = '\0';

}

int convertCharToInt(char ch) {
	return ch - '0';
}

double convertStringToNumber(const char* numberInString) {

	double number = 0;

	while (*numberInString)
	{
		number = number * 10 + convertCharToInt(*numberInString);
		numberInString++;
	}

	return number;
}

Pair convertStringToPair(const char* numberInString) {

	Pair p;

	if (!numberInString) {
		p.number = 0;
		stringCopy(p.ErrorCode, "Invalid input!");	
	}


	p.number = convertStringToNumber(numberInString);
	stringCopy(p.ErrorCode, "OK");

	return p;
}

int main() {
	Pair p;
	char* text = new char(100);
	std::cin >> text;
	p = convertStringToPair(text);
	printPair(p);

}
