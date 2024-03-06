#pragma once

#include "../editor/editor.hpp"
#include "command.hpp"

class BackspaceCommand : public Command{
public:
    BackspaceCommand(Editor& editor);
    void execute() override;
    void undo() override;
    std::unique_ptr<Command> clone() const override;

private:
    Editor& _currentEditor;
    std::string _prevBuf;
    size_t _beforeCurrent;
};