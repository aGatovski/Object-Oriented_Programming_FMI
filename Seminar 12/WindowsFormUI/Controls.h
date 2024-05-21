#pragma once
#include<iostream>

class Controls {
public:
	virtual void setDataDialog(const char* dataText) = 0;
	virtual ~Controls() = default;
	virtual Controls* clone() const = 0;
protected:
	unsigned controlWidth = 0;
	unsigned controlHeight = 0;

	struct point
	{
		int x;
		int y;

		point() :x(0), y(0) {}
		point(int x, int y) :x(x), y(y) {}
		
		const point& getStartingPoint() const{
			return (*this);
		}
	};
};
