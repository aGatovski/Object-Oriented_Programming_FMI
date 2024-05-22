#include "CheckBox.h"

CheckBox::CheckBox()
{
    checkBoxName = new char[1];
    checkBoxName = '\0';
}

CheckBox::CheckBox(const CheckBox& other) : Controls(other)
{
    copyFrom(other);
}

CheckBox& CheckBox::operator=(const CheckBox& other)
{
    if (this != &other) {
        free();
        Controls::operator=(other);
        copyFrom(other);
    }
    return *this;
    // TODO: insert return statement here
}

CheckBox::CheckBox(CheckBox&& other) noexcept : Controls(std::move(other))
{
    moveFrom(std::move(other));
}

CheckBox& CheckBox::operator=(CheckBox&& other) noexcept
{
    if (this != &other) {
        free();
        Controls::operator=(std::move(other));
        moveFrom(std::move(other));
    }
    return *this;
    // TODO: insert return statement here
}

CheckBox::~CheckBox()
{
    free();
}

void CheckBox::setDataDialog(const char* dataText)
{
    delete[] checkBoxName;
    checkBoxName = new char[strlen(dataText) + 1];
    strcpy(checkBoxName, dataText);

    state = (!state);
}

Controls* CheckBox::clone() const
{
    return new CheckBox(*this);
}

void CheckBox::copyFrom(const CheckBox& other)
{
 /*   controlWidth = other.controlWidth;
    controlHeight = other.controlHeight;*/
    checkBoxName = new char[strlen(other.checkBoxName) + 1];
    strcpy(checkBoxName, other.checkBoxName);
    state = other.state;
}

void CheckBox::moveFrom(CheckBox&& other) noexcept
{
   /* controlWidth = other.controlWidth;
    controlHeight = other.controlHeight;
    other.controlHeight = 0;
    other.controlWidth = 0;*/
    checkBoxName = other.checkBoxName;
    other.checkBoxName = nullptr;
    state = other.state;
}

void CheckBox::free()
{
    delete[] checkBoxName; 
    checkBoxName = nullptr;
}
