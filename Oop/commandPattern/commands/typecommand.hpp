#pragma once

#include "../editor/editor.hpp"
#include "command.hpp"

class TypeCommand : public Command{
public:
    TypeCommand(Editor& editor, const char& c);
    void execute() override;
    void undo() override;
    std::unique_ptr<Command> clone() const override;
private:
    Editor& _currentEditor;
    char toAdd;
    std::string _prevBuf;
    size_t _beforeCurrent;
};