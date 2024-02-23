#include <iostream>

struct empty {
};

struct test1 {
	int number;
};

struct test2 {
	char symbol;
	int number;
};

struct test3 {
	char symbol;
	short sh;
	int number;
};

struct test4 {
	char symbol1;
	int number;
	char symbol2;
};

struct student {
	char* name;
	int* grades;
};

struct test5 {
	char a[5];
	int b;
	double c;
};

struct test6 {
	char a[3];
	short b;
	double c[4];
	char d;
};

int main()
{
	//std::cout << sizeof(empty);  //1
	//std::cout << sizeof(test1);  //4
	//std::cout << sizeof(test2);  //8
	//std::cout << sizeof(test3);  //8
	std::cout << sizeof(test3);
}
