#pragma once

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include "geocordObject.hpp"

class AskWidget : public QWidget{
    Q_OBJECT;

public:
    AskWidget(QWidget *parent = nullptr);

public slots:
    void onAskFindButton();
    void onClearButton();

private:
    QLineEdit *askEdit;
    QPushButton *askFindButton;
    QPushButton *clearButton;
    QTextEdit *askResultEdit;
    GeocordObject tempObject;

};