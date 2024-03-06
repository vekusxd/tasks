#pragma once

#include <string>

class Editor
{
public:
    Editor();

    void type(const char& c);
    void backspace();
    void shiftLeft();
    void shiftRight();

    std::string getText() const;
    size_t getCurrentPos() const;

    void setText(const std::string& s);
    void setCursor(size_t pos);

private:
    std::string _buf;
    size_t _current;
};
