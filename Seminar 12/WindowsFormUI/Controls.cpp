#include "Controls.h"

//Controls::Controls(ControlType _type, size_t _controlWidth, size_t _controlHeight, size_t _x, size_t _y) : type(_type) , controlHeight(controlHeight), controlWidth(_controlWidth) 
//{
//	locationPoint = point(_x, _y);
//}

Controls::Controls(ControlType _type, size_t _controlWidth, size_t _controlHeight, size_t _startingHeight, size_t _startingWidth)
: type(_type), controlHeight(controlHeight), controlWidth(_controlWidth) , startingHeight(_startingHeight) , startingWidth(_startingWidth) { }

ControlType Controls::getType() const
{
	return type;
}

size_t Controls::getHeight() const
{
	return controlHeight;
}

size_t Controls::getWidth() const
{
	return controlWidth;
}

size_t Controls::getStartingHeight() const
{
	return startingHeight;
}

size_t Controls::getStartingWidth() const
{
	return startingWidth;
}

void Controls::resize(size_t _controlWidth, size_t _controlHeight)
{
	controlWidth = _controlWidth;
	controlHeight = _controlHeight;
}

void Controls::changeLocation(size_t _controlStartingWidth, size_t _controlStartingHeight)
{
	controlWidth  = _controlStartingWidth;
	controlHeight = _controlStartingHeight;
}
