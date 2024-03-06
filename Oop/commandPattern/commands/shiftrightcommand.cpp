#include "shiftrightcommand.hpp"

ShiftRightCommand::ShiftRightCommand(Editor &editor)
    : _currentEditor(editor)
    , _beforeCurrent{}
{}

void ShiftRightCommand::execute()
{
    _beforeCurrent = _currentEditor.getCurrentPos();
    _currentEditor.shiftRight();
}

void ShiftRightCommand::undo()
{
    _currentEditor.setCursor(_beforeCurrent);
}

std::unique_ptr<Command> ShiftRightCommand::clone() const
{
    return std::make_unique<ShiftRightCommand>(*this);
}
