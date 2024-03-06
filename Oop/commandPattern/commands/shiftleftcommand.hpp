#pragma once

#include "../editor/editor.hpp"
#include "command.hpp"

class ShiftLeftCommand : public Command{
public:
    ShiftLeftCommand(Editor& editor);
    void execute() override;
    void undo() override;
    std::unique_ptr<Command> clone() const override;

private:
    Editor& _currentEditor;
    size_t _beforeCurrent;
};