#include "editor.hpp"

Editor::Editor()
    : _buf{}, _current{}
{}

void Editor::type(const char &c){
    _buf.insert(_buf.begin() + _current, c);
    ++_current;
}

void Editor::backspace(){
    if(_current != 0){
        _buf.erase(_buf.begin() + (--_current));
    }
}

std::string Editor::getText() const{
    return _buf;
}

void Editor::shiftLeft(){
    _current = (_current == 0) ? _current : --_current;
}

void Editor::shiftRight(){
    _current = (_current == _buf.size()) ? _current : ++_current;
}


size_t Editor::getCurrentPos() const
{
    return _current;
}

void Editor::setText(const std::string& s){
    _buf = s;
    if(_current > s.size()){
        _current = s.size();
    }
}

void Editor::setCursor(size_t size){
    if(size > _buf.size()){
        _current = _buf.size();
    }
    else{
        _current = size;
    }
}

