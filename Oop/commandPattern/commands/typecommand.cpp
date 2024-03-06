#include "typecommand.hpp"

TypeCommand::TypeCommand(Editor &editor, const char &c)
    : _currentEditor(editor)
    , toAdd(c)
    , _prevBuf{}
    , _beforeCurrent{}
{}

void TypeCommand::execute()
{
    _prevBuf = _currentEditor.getText();
    _beforeCurrent = _currentEditor.getCurrentPos();
    _currentEditor.type(toAdd);
}

void TypeCommand::undo()
{
    _currentEditor.setText(_prevBuf);
    _currentEditor.setCursor(_beforeCurrent);
}

std::unique_ptr<Command> TypeCommand::clone() const
{
    return std::make_unique<TypeCommand>(*this);
}
