#pragma once

#include <QWidget>
#include <QCheckBox>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include "askwidget.hpp"

class Widget : public QWidget{
    Q_OBJECT;

public:
    Widget(QWidget *parent = nullptr);

public slots:
    void onChangeButton();
    void onFindButton();
    void onAsk();
    void onClearButton();


private:
    QCheckBox *plainCheck;
    QCheckBox *trainCheck;
    QCheckBox *suburbanCheck;
    QCheckBox *busCheck;

    QLineEdit *fromEdit;
    QLineEdit *toEdit;
    QLineEdit *dateEdit;

    AskWidget *ask;

    QPushButton *changeButton;
    QPushButton *findButton;
    QPushButton *findStations;
    QPushButton *clearButton;

    QTextEdit *resultEdit;
};