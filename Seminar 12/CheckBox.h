#pragma once
#include"Controls.h"
#include <iostream>

class CheckBox : public Controls {
public:
	CheckBox();
	CheckBox(const CheckBox& other);
	CheckBox& operator=(const CheckBox& other);
	CheckBox(CheckBox&& other) noexcept;
	CheckBox& operator=(CheckBox&& other) noexcept;
	~CheckBox();



	void setDataDialog(const char* dataText) override;
	Controls* clone() const override;
private:
	bool state = 1; //  0 on 1 off
	char* checkBoxName = nullptr;



	void copyFrom(const CheckBox& other);
	void moveFrom(CheckBox&& other) noexcept;
	void free();
};
