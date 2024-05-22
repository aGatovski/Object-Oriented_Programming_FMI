#include "RadioButton.h"

RadioButton::RadioButton()
{

    radioButtonOptions[0] ='\0';
}

RadioButton::RadioButton(const char** _radioButtonOptions, unsigned short _chosen, unsigned _radioButtonOptionsCount)
{
    radioButtonOptionsCount = _radioButtonOptionsCount;
    chosen = _chosen;
    radioButtonOptions = new char* [radioButtonOptionsCount];
    for (size_t i = 0; i < radioButtonOptionsCount; i++) {
        radioButtonOptions[i] = new char[strlen(_radioButtonOptions[i]) + 1];
        strcpy(radioButtonOptions[i], _radioButtonOptions[i]);
    }

}

RadioButton::RadioButton(const RadioButton& other) :Controls(other)
{
    copyFrom(other);
}

RadioButton& RadioButton::operator=(const RadioButton& other)
{
    if (this != &other) {
        free();
        Controls::operator=(other);
        copyFrom(other);
    }
    return *this;
    // TODO: insert return statement here
}

RadioButton::RadioButton(RadioButton&& other) noexcept : Controls(std::move(other))
{
    moveFrom(std::move(other));
}

RadioButton& RadioButton::operator=(RadioButton&& other) noexcept
{
    if (this != &other) {
        free();
        Controls::operator=(std::move(other));
        moveFrom(std::move(other));
    }
    return *this;
    // TODO: insert return statement here
}

RadioButton::~RadioButton()
{
    free();
}

void RadioButton::setDataDialog(const char* dataText)
{
    delete[] radioButtonOptions[chosen];
    radioButtonOptions[chosen] = new char[strlen(dataText) + 1];
    strcpy(radioButtonOptions[chosen], dataText);
}

RadioButton* RadioButton::clone() const
{
    return new RadioButton(*this);
}

void RadioButton::copyFrom(const RadioButton& other)
{
    chosen = other.chosen;
    radioButtonOptionsCount = other.radioButtonOptionsCount;

    radioButtonOptions = new char* [radioButtonOptionsCount];

    for (size_t i = 0; i < radioButtonOptionsCount; i++){
        radioButtonOptions[i] = new char[strlen(other.radioButtonOptions[i]) + 1];
        strcpy(radioButtonOptions[i], other.radioButtonOptions[i]);
    }
}

void RadioButton::moveFrom(RadioButton&& other)
{
    chosen = other.chosen;
    other.chosen = 0;
    radioButtonOptionsCount = other.radioButtonOptionsCount;
    other.radioButtonOptionsCount = 0;
    radioButtonOptions = other.radioButtonOptions;
    other.radioButtonOptions = nullptr;
}

void RadioButton::free()
{
    for (size_t i = 0; i < radioButtonOptionsCount; i++){
        delete[] radioButtonOptions[i];
    }
    delete[] radioButtonOptions;
}
