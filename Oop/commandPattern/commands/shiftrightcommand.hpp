#pragma once

#include "../editor/editor.hpp"
#include "command.hpp"

class ShiftRightCommand : public Command{
public:
    ShiftRightCommand(Editor& editor);
    void execute() override;
    void undo() override;
    std::unique_ptr<Command> clone() const override;

private:
    Editor& _currentEditor;
    size_t _beforeCurrent;
};