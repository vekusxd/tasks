#include "emptycommand.hpp"

#include <iostream>

EmptyCommand::EmptyCommand()
{}

void EmptyCommand::execute()
{
    std::cout << "Empty execute command\n";
}

void EmptyCommand::undo()
{
    std::cout <<  "Empty undo command\n";
}

std::unique_ptr<Command> EmptyCommand::clone() const
{
    return std::make_unique<EmptyCommand>(*this);
}
