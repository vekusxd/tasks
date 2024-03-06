#include "shiftleftcommand.hpp"

ShiftLeftCommand::ShiftLeftCommand(Editor &editor)
    : _currentEditor(editor)
    , _beforeCurrent{}
{}

void ShiftLeftCommand::execute()
{
    _beforeCurrent = _currentEditor.getCurrentPos();
    _currentEditor.shiftLeft();
}

void ShiftLeftCommand::undo()
{
    _currentEditor.setCursor(_beforeCurrent);
}

std::unique_ptr<Command> ShiftLeftCommand::clone() const
{
    return std::make_unique<ShiftLeftCommand>(*this);
}
