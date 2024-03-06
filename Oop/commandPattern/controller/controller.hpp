#pragma once

#include <memory>
#include <vector>

#include "../commands/command.hpp"
#include "../editor/editor.hpp"

class Controller{
public:
    Controller(Editor& editor);

    void on_button_1();
    void on_button_2();
    void on_button_3();
    void on_button_4();

    void setButton1Listener(Command* command);
    void setButton2Listener(Command* command);
    void setButton3Listener(Command* command);
    void setButton4Listener(Command* command);

    void undo();
    void redo();

    std::string getText() const;
    size_t getCurrentPose() const;

private:
    void onNewCommand(Command* command);

private:
    Editor& _currentEditor;
    size_t _currentCommand;

    std::unique_ptr<Command> button_1;
    std::unique_ptr<Command> button_2;
    std::unique_ptr<Command> button_3;
    std::unique_ptr<Command> button_4;

    
    std::vector<std::unique_ptr<Command>> commandsHistory;
};