#pragma once
#include "Controls.h"

class Label :public Controls {
public:
	Label();
	Label(const Label& other);
	Label& operator=(const Label& other);
	Label(Label&& other) noexcept;
	Label& operator=(Label&& other) noexcept;
	~Label();



	void setDataDialog(const char* dataText) override;
	Controls* clone() const override;

private:
	char* labelText = nullptr;


	void copyFrom(const Label& other);
	void moveFrom(Label&& other) noexcept;
	void free();
};