#include "backspacecommand.hpp"

BackspaceCommand::BackspaceCommand(Editor &editor)
    : _currentEditor(editor)
    , _prevBuf{}
    , _beforeCurrent{}
{}

void BackspaceCommand::execute()
{
    _prevBuf = _currentEditor.getText();
    _beforeCurrent = _currentEditor.getCurrentPos();
    _currentEditor.backspace();
}

void BackspaceCommand::undo()
{
    _currentEditor.setText(_prevBuf);
    _currentEditor.setCursor(_beforeCurrent);
}

std::unique_ptr<Command> BackspaceCommand::clone() const
{
    return std::make_unique<BackspaceCommand>(*this);
}
