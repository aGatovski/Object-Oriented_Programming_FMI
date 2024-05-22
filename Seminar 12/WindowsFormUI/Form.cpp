#include "Form.h"
#include"ControlFactory.h"


Form::Form(size_t _formWidth, size_t _formHeight, const char* _formName) : formWidth(_formWidth), formHeight(_formHeight)
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

void Form::resizeData()
{
	Controls** dataTemp = new Controls*[dataCapacity * 2];
	for (size_t i = 0; i < dataSize; i++){
		dataTemp[i] = data[i];
	}
	delete[] data;
	data = dataTemp;
}

void Form::resizeForm(size_t _formWidth, size_t _formHeight)
{
	formWidth = _formWidth;
	formHeight = _formHeight;
}

void Form::resizeControlAtIndex(size_t index, size_t _controlWidth, size_t _controlHeight)
{
	if (index > dataSize) {
		throw std::out_of_range("The index given is out of bounds!");
	}

	if (((data[index]->getStartingHeight() + _controlHeight) > formHeight) || ((data[index]->getStartingWidth() + _controlWidth) > formWidth)) {
		throw std::invalid_argument("Invalid controler size!");
	}
	
	data[index]->resize( _controlWidth, _controlHeight);

}

void Form::changeControlLocationAtIndex(size_t index, size_t _controlStartingWidth, size_t _controlStartingHeight)
{
	if (index > dataSize) {
		throw std::out_of_range("The index given is out of bounds!");
	}
	if (((data[index]->getHeight() + _controlStartingHeight) > formHeight) || ((data[index]->getWidth() + _controlStartingWidth) > formWidth)) {
		throw std::invalid_argument("Invalid controler location!");
	}


}

void Form::change(size_t index, const char* controlText)
{
	if (index > dataSize) {
		throw std::out_of_range("The index given is out of bounds!");
	}
	data[index]->setDataDialog(controlText);
}

void Form::addControl(ControlType controlType)
{
	if (dataSize == dataCapacity) {
		resizeData();
	}
	data[dataSize++] = controlFactory(controlType);
}

void Form::addControl(const Controls& control)
{
	if (dataSize == dataCapacity) {
		resizeData();
	}
	data[dataSize++] = control.clone();
}

void Form::addLabel()
{
	if (dataSize == dataCapacity) {
		resizeData();
	}
	data[dataSize++] = new Label();
}

void Form::addCheckBox()
{
	if (dataSize == dataCapacity) {
		resizeData();
	}
}

void Form::addRadioButton()
{
	if (dataSize == dataCapacity) {
		resizeData();
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
