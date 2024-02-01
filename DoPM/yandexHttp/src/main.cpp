#include <QApplication>
#include "../include/widget.hpp"

int main(int argc, char **argv){
    QApplication app(argc, argv);

    Widget widget;
    widget.setWindowTitle("Yandex api");
    widget.setFixedSize(900, 700);

    widget.show();
    return app.exec();
}