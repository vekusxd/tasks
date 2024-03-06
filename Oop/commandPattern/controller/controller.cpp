#include <iostream>

#include "controller.hpp"
#include "../commands/emptycommand.hpp"


Controller::Controller(Editor &editor)
    :  _currentEditor(editor)
    , _currentCommand{}
    ,  button_1{std::make_unique<EmptyCommand>()}
    ,  button_2{std::make_unique<EmptyCommand>()}
    ,  button_3{std::make_unique<EmptyCommand>()}
    ,  button_4{std::make_unique<EmptyCommand>()}
    , commandsHistory{}
{}

void Controller::onNewCommand(Command* command)
{
    if(_currentCommand == commandsHistory.size()){
        command->execute();
    }
    else{
        commandsHistory.erase(commandsHistory.begin() + _currentCommand, commandsHistory.end());
        command->execute();
    }
    _currentCommand++;
    commandsHistory.push_back(command->clone());
}

void Controller::on_button_1()
{
    onNewCommand(button_1.get());
}

void Controller::on_button_2()
{
    onNewCommand(button_2.get());
}

void Controller::on_button_3()
{
   onNewCommand(button_3.get());
}

void Controller::on_button_4()
{
    onNewCommand(button_4.get());
}

void Controller::setButton1Listener(Command* command)
{
    button_1.reset(command);
}

void Controller::setButton2Listener(Command* command)
{
    button_2.reset(command);
}

void Controller::setButton3Listener(Command* command)
{
    button_3.reset(command);
}

void Controller::setButton4Listener(Command* command)
{
    button_4.reset(command);
}

void Controller::undo()
{
    if(_currentCommand != 0){
        commandsHistory[--_currentCommand]->undo();
    }
}

void Controller::redo()
{
    if(_currentCommand != commandsHistory.size()){
        commandsHistory[_currentCommand]->execute();
        _currentCommand++;
    }
}

std::string Controller::getText() const {
    return _currentEditor.getText();
}

size_t Controller::getCurrentPose() const
{
    return _currentEditor.getCurrentPos();
}
