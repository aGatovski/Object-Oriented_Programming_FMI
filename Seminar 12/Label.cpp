#include "Label.h"

Label::Label()
{
    labelText =new char[1];
    labelText = '\0';
}

Label::Label(const Label& other) : Controls(other)
{
    copyFrom(other);
}

Label& Label::operator=(const Label& other) 
{
    if (this != &other) {
        free();
        Controls::operator=(other);
        copyFrom(other);
    }
    return *this;
    // TODO: insert return statement here
}

Label::Label(Label&& other)  noexcept : Controls(other)
{
    moveFrom(std::move(other));
}

Label& Label::operator=(Label&& other) noexcept
{
    if (this != &other) {
        free();
        Controls::operator=(std::move(other));
        moveFrom(std::move(other));
    }
    return *this;
    // TODO: insert return statement here
}

Label::~Label()
{
    free();
}

void Label::setDataDialog(const char* dataText)
{
    labelText = new char[strlen(dataText) + 1];
    strcpy(labelText, dataText);
}

Controls* Label::clone() const
{
    return  new Label(*this);
}

void Label::copyFrom(const Label& other) 
{
  /*  controlWidth = other.controlWidth;
    controlHeight = other.controlHeight;*/
    labelText = new char[strlen(other.labelText) + 1];
    strcpy(labelText, other.labelText);
}

void Label::moveFrom(Label&& other) noexcept
{
   /* controlWidth = other.controlWidth;
    controlHeight = other.controlHeight;
    other.controlHeight = 0;
    other.controlWidth = 0;*/
    labelText = other.labelText;
    other.labelText = nullptr;
}

void Label::free()
{
    delete[] labelText;
    labelText = nullptr;
}
