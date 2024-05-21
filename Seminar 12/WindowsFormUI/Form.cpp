#include "Form.h"

Form::Form(unsigned _formWidth, unsigned _formHeight, const char* _formName) : formWidth(_formWidth), formHeight(_formHeight)
{
	formName = new char[strlen(_formName) + 1];
	strcpy(formName, _formName);
}

Form::Form(const Form& other)
{
	copyFrom(other);
}

Form& Form::operator=(const Form& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
	// TODO: insert return statement here
}

Form::Form(Form&& other) noexcept
{
	moveFrom(std::move(other));
}

Form& Form::operator=(Form&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
	// TODO: insert return statement here
}

Form::~Form()
{
	free();
}

void Form::resize()
{
	Controls** dataTemp = new Controls*[dataCapacity * 2];
	for (size_t i = 0; i < dataSize; i++){
		dataTemp[i] = data[i];
	}
	delete[] data;
	data = dataTemp;
}

//void Form::addControl(Controls controlType)
//{
//	if (dataSize == dataCapacity) {
//		resize();
//	}
//
//	data[dataSize++] = Controls(controlType);
//}

void Form::addControl(const Controls& control)
{
	if (dataSize == dataCapacity) {
		resize();
	}
	data[dataSize++] = control.clone();
}

void Form::addLabel()
{
	if (dataSize == dataCapacity) {
		resize();
	}
	data[dataSize++] = new Label();
}

void Form::addCheckBox()
{
	if (dataSize == dataCapacity) {
		resize();
	}
}

void Form::addRadioButton()
{
	if (dataSize == dataCapacity) {
		resize();
	}
}

void Form::copyFrom(const Form& other)
{
	formHeight = other.formHeight;
	formWidth = other.formWidth;

	formName = new char[strlen(other.formName) + 1];
	strcpy(formName, other.formName);

	data = new Controls*[other.dataCapacity];

	for (size_t i = 0; i < dataSize; i++){
		data[i] = other.data[i]->clone();
		//data[i] = (*(other.data[i])).clone();
	}

	dataCapacity = other.dataCapacity;
	dataSize = other.dataSize;
}

void Form::moveFrom(Form&& other)
{
	data = other.data;
	other.formName = nullptr;
	dataCapacity = other.dataCapacity;
	dataSize = other.dataSize;

	formName = other.formName;
	other.formName = nullptr;
	formHeight = other.formHeight;
	formWidth = other.formWidth;
}

void Form::free()
{
	delete[] formName;
	formName = nullptr;
	for (size_t i = 0; i < dataSize; i++){
		delete data[i];
	}

	delete[] data;
	data = nullptr;
}
