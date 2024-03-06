#include <iostream>

#include "controller/controller.hpp"
#include  "commands/backspacecommand.hpp"
#include "commands/shiftleftcommand.hpp"
#include "commands/shiftrightcommand.hpp"
#include "commands/typecommand.hpp"
#include "editor/editor.hpp"

int main(){
    Editor editor;

    Controller controller(editor);

    controller.setButton1Listener(new TypeCommand(editor, 'c'));
    controller.setButton2Listener(new TypeCommand(editor, 'h'));
    controller.setButton3Listener(new BackspaceCommand(editor));
    controller.setButton4Listener(new ShiftLeftCommand(editor));

    controller.on_button_1();
    controller.on_button_1();
    controller.on_button_1();
    controller.on_button_2();

    std::cout <<  "Current text and cursor pos: " << controller.getText() << ", " << controller.getCurrentPose() << std::endl;

    controller.undo();
    controller.undo();

    std::cout <<  "Current text and cursor pos: " << controller.getText() << ", " << controller.getCurrentPose() << std::endl;

    controller.redo();
    controller.redo();
    controller.redo();
    controller.redo();
    controller.redo();
    controller.redo();

    std::cout <<  "Current text and cursor pos: " << controller.getText() << ", " << controller.getCurrentPose() << std::endl;


    controller.on_button_3();
    controller.on_button_3();

    std::cout <<  "Current text and cursor pos: " << controller.getText() << ", " << controller.getCurrentPose() << std::endl;

    controller.undo();

    std::cout <<  "Current text and cursor pos: " << controller.getText() << ", " << controller.getCurrentPose() << std::endl;
    
    controller.undo();
    std::cout <<  "Current text and cursor pos: " << controller.getText() << ", " << controller.getCurrentPose() << std::endl;

    controller.on_button_4();
    controller.on_button_4();
    controller.on_button_4();
    controller.on_button_4();

    std::cout <<  "Current text and cursor pos: " << controller.getText() << ", " << controller.getCurrentPose() << std::endl;

    controller.undo();
    controller.undo();

    std::cout <<  "Current text and cursor pos: " << controller.getText() << ", " << controller.getCurrentPose() << std::endl;

    controller.redo();
    std::cout <<  "Current text and cursor pos: " << controller.getText() << ", " << controller.getCurrentPose() << std::endl;

    controller.redo();
    controller.redo();
    controller.redo();
    controller.redo();
    controller.redo();

    std::cout <<  "Current text and cursor pos: " << controller.getText() << ", " << controller.getCurrentPose() << std::endl;

    controller.on_button_2();
    controller.on_button_2();
    controller.on_button_2();
    controller.on_button_2();

    std::cout <<  "Current text and cursor pos: " << controller.getText() << ", " << controller.getCurrentPose() << std::endl;

    controller.undo();

    std::cout <<  "Current text and cursor pos: " << controller.getText() << ", " << controller.getCurrentPose() << std::endl;

    controller.redo();

    std::cout <<  "Current text and cursor pos: " << controller.getText() << ", " << controller.getCurrentPose() << std::endl;
}