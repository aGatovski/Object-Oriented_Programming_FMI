#include <iostream>

struct ComplexNumber {

	int realPart;
	int complexPart;
};

void initializeComplexNumber(ComplexNumber& c) {
	std::cin >> c.realPart >> c.complexPart;
}

void printComplexNumber(const ComplexNumber& c) {

	if (c.complexPart >+ 0) {
		std::cout << c.realPart << "+" << c.complexPart << "i";
	}
	else std::cout << c.realPart << " " << c.complexPart<<"i";

}

ComplexNumber sumComplexNumbers(const ComplexNumber& c1, const ComplexNumber& c2) {

	ComplexNumber sum;
	sum.realPart = c1.realPart + c2.realPart;
	sum.complexPart = c1.complexPart + c2.complexPart;

	return sum;

}

int main() {

	ComplexNumber c1,c2;
	initializeComplexNumber(c1);
	initializeComplexNumber(c2);
	//initializeComplexNumber(c);
	//printComplexNumber(c);

	printComplexNumber(sumComplexNumbers(c1, c2));
}
