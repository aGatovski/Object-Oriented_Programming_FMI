#pragma once
#include<iostream>

enum class ControlType {
	label,
	checkBox,
	radioButton
};

class Controls {
public:
	Controls() = default;
	//Controls(ControlType type,size_t _controlWidth , size_t _controlHeight, size_t _x, size_t _y);
	Controls(ControlType _type, size_t _controlWidth, size_t _controlHeight, size_t _startingHeight, size_t _startingWidth);
	ControlType getType() const;
	
	virtual ~Controls() = default;
	virtual Controls* clone() const = 0;
	virtual void setDataDialog(const char* dataText) = 0;
	
	size_t getHeight() const;
	size_t getWidth() const;
	size_t getStartingHeight() const;
	size_t getStartingWidth() const ;

	void resize(size_t _controlWidth, size_t _controlHeight);
	void changeLocation(size_t _controlStartingWidth, size_t _controlStartingHeight);

protected:
	/*struct point
	{
		size_t x;
		size_t y;

		point() :x(0), y(0) {}
		point(size_t x, size_t y) :x(x), y(y) {}

		const point& getStartingPoint() const {
			return (*this);
		}
	};*/

	size_t controlWidth = 0;
	size_t controlHeight = 0;
	/*point locationPoint;*/


	size_t startingHeight = 0;
	size_t startingWidth = 0;
private:
	ControlType type;
};
