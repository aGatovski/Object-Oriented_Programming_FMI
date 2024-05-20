#pragma once
#include<iostream>
#include"Controls.h"
#include "Label.h"

class Form {
public:
	Form() = default;
	Form(unsigned _formWidth,unsigned _formHeight, const char* _formName);
	Form(const Form& other);
	Form& operator=(const Form& other) ;
	Form(Form&& other) noexcept;
	Form& operator=(Form&& other) noexcept;
	~Form();


	void resize();

	/*void addControl(Controls controlType);*/
	void addControl(const Controls& control);

	void addLabel();
	void addCheckBox();
	void addRadioButton();

private:
	unsigned formWidth = 0;
	unsigned formHeight = 0;
	char* formName = nullptr;

	Controls** data = nullptr;
	unsigned dataSize = 0;
	unsigned dataCapacity = 0;

	  
	void copyFrom(const Form& other);
	void moveFrom(Form&& other) noexcept;
	void free();
};