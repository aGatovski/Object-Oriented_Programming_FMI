#include "ControlFactory.h"
#include"Label.h"
#include"RadioButton.h"
#include"CheckBox.h"

Controls* controlFactory(ControlType controlType)
{
	switch (controlType)
	{
	case ControlType::label: return new Label();
		break;
	case ControlType::checkBox: return new CheckBox();
		break;
	case ControlType::radioButton: return new RadioButton();
		break;
	default: throw std::invalid_argument("Invalid control type!");
		break;
	}
}
