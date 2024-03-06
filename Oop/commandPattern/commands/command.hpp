#pragma once

#include <memory>

class Command{
public:
    virtual ~Command() {}
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual std::unique_ptr<Command> clone() const = 0;
};