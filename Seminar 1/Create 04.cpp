#include <iostream>

struct Point {
	int x = 0;
	int y = 0;
};

struct Circle {

unsigned radius;
};

void initialiseCircle(Circle& c) {
	std::cin >> c.radius;
}

bool pointInCircle(const Circle& c, const Point& p) {

	if ((p.x * p.x) + (p.y * p.y) == (c.radius * c.radius)) {
		return true;
	}
	return false;

}

void initialisePoint(Point& p) {
	std::cin >> p.x >> p.y;
}

void printPoint(const Point& p) {
	std::cout << p.x << " " << p.y;
}

double findDistanceFromZero(const Point& p) {
	return  sqrt((p.x * p.x) + (p.y * p.y));;

}

double findDistanceBetweenTwoPoints(const Point& p1, const Point& p2){

	return sqrt(((p2.x - p1.x) * (p2.x - p1.x)) + (p2.y - p1.y) * (p2.y - p1.y));

}

unsigned findQuadrant(const Point& p) {

	if (p.x == 0 || p.y == 0) {
		return 0;
	}

	else if (p.x > 0) {
		if (p.y > 0) {
			return 1;
		}

		else return 4;
	}

	else {
		if (p.y > 0) {
			return 2;
		}

		else return 3;

	}
}



int main() {
	Circle c;
	initialiseCircle(c);

	Point p1,p2;
	initialisePoint(p1);
	initialisePoint(p2);
	//printPoint(p);
	std::cout<<std::endl;
	std::cout << findDistanceBetweenTwoPoints(p1,p2)<<std::endl;
	std::cout << findQuadrant(p1);

	std::cout << pointInCircle(c,p1);
}
