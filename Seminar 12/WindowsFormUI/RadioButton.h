#pragma once
#include "Controls.h"
#include<iostream>

class RadioButton : public Controls {
public:
	RadioButton();
	RadioButton(const char** _radioButtonOptions, unsigned short _chosen, unsigned _radioButtonOptionsCount);
	RadioButton(const RadioButton& other);
	RadioButton& operator=(const RadioButton& other);
	RadioButton(RadioButton&& other) noexcept;
	RadioButton& operator=(RadioButton&& other) noexcept;
	~RadioButton();

	void setDataDialog(const char* dataText) override;
	RadioButton* clone() const override;

private:
	char** radioButtonOptions = nullptr;
	unsigned radioButtonOptionsCount = 0;
	unsigned short chosen = 0;

	void copyFrom(const RadioButton& other);
	void moveFrom(RadioButton&& other);
	void free();
};