#pragma once

#include "command.hpp"
#include "../editor/editor.hpp"

class EmptyCommand : public Command{
public:
    EmptyCommand();
    void execute() override;
    void undo() override;
    std::unique_ptr<Command> clone() const override;
};