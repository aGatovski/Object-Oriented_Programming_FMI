#pragma once
#include<iostream>
#include"Controls.h"
#include "Label.h"

class Form {
public:
	Form() = default;
	Form(size_t _formWidth, size_t _formHeight, const char* _formName);
	Form(const Form& other);
	Form& operator=(const Form& other) ;
	Form(Form&& other) noexcept;
	Form& operator=(Form&& other) noexcept;
	~Form();

	void resizeData();

	void addControl(ControlType controlType);
	void addControl(const Controls& control);
	void addLabel();
	void addCheckBox();
	void addRadioButton();
	
	void resizeForm(size_t _formWidth,size_t _formHeight);
	void resizeControlAtIndex(size_t index, size_t _controlWidth , size_t _controlHeight);

	void changeControlLocationAtIndex(size_t index, size_t _controlStartingWidth, size_t _controlStartingHeight);
	void change(size_t index,const char* controlText);



private:
	size_t formWidth = 0;
	size_t formHeight = 0;
	char* formName = nullptr;

	Controls** data = nullptr;
	size_t dataSize = 0;
	size_t dataCapacity = 0;

	  
	void copyFrom(const Form& other);
	void moveFrom(Form&& other) noexcept;
	void free();
};