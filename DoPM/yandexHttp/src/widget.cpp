#include "../include/widget.hpp"
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>

Widget::Widget(QWidget *parent) : QWidget(parent){
    QVBoxLayout *vLayout = new QVBoxLayout(this);

    QLabel *titleLable = new QLabel("Расписание транспорта");
    titleLable->setAlignment(Qt::AlignCenter);
    vLayout->addWidget(titleLable);

    QHBoxLayout *checkButtonsLayout = new QHBoxLayout;

    plainCheck = new QCheckBox("Самолет");
    trainCheck = new QCheckBox("Поезд");
    suburbanCheck = new QCheckBox("Электричка");
    busCheck = new QCheckBox("Автобус");
    findStations = new QPushButton("&Найти ближайшие станции");
    clearButton = new QPushButton("&Очистить");

    checkButtonsLayout->addWidget(plainCheck);
    checkButtonsLayout->addWidget(trainCheck);
    checkButtonsLayout->addWidget(suburbanCheck);
    checkButtonsLayout->addWidget(busCheck);
    checkButtonsLayout->addWidget(findStations);
    checkButtonsLayout->addWidget(clearButton);

    vLayout->addLayout(checkButtonsLayout);

    
    QHBoxLayout *secondRawLayout = new QHBoxLayout;

    fromEdit = new QLineEdit;
    fromEdit->setPlaceholderText("Откуда");
    changeButton = new QPushButton("&смена");
    toEdit = new QLineEdit;
    toEdit->setPlaceholderText("Куда");
    dateEdit = new QLineEdit;
    dateEdit->setPlaceholderText("Дата");
    findButton = new QPushButton("&найти");

    secondRawLayout->addWidget(fromEdit);
    secondRawLayout->addWidget(changeButton);
    secondRawLayout->addWidget(toEdit);
    secondRawLayout->addWidget(dateEdit);
    secondRawLayout->addWidget(findButton);

    vLayout->addLayout(secondRawLayout);

    resultEdit = new QTextEdit;
    resultEdit->setReadOnly(true);

    vLayout->addWidget(resultEdit);


    ask = new AskWidget;
    ask->setFixedSize(600, 400);


    connect(changeButton, &QPushButton::pressed, this, &Widget::onChangeButton);
    connect(findButton, &QPushButton::pressed, this, &Widget::onFindButton);
    connect(findStations, &QPushButton::pressed, this, &Widget::onAsk);
    connect(clearButton, &QPushButton::clicked, this, &Widget::onClearButton);
}

void Widget::onChangeButton(){
    QString temp = fromEdit->text();
    fromEdit->setText(toEdit->text());
    toEdit->setText(temp);
}

void Widget::onFindButton(){
    if(fromEdit->text().isEmpty() || toEdit->text().isEmpty()){
        QMessageBox error;
        error.setText("Поля \"откуда\" и \"куда\" должны быть заполнены!");
        error.setIcon(QMessageBox::Critical);
        error.setStandardButtons(QMessageBox::Ok);

        error.exec();
        return;
    }
    if(dateEdit->text().isEmpty()){
        QMessageBox warning;
        warning.setText("В случае отсутствия даты будут показываться все ближайшие рейсы");
        warning.setIcon(QMessageBox::Warning);

        QPushButton *yesButton = warning.addButton("Я понимаю", QMessageBox::YesRole);
        QPushButton *noButton = warning.addButton("отмена", QMessageBox::NoRole);


        warning.exec();
        //return;
    }

    if(!plainCheck->isChecked() && !trainCheck->isChecked() && !suburbanCheck->isChecked() && !busCheck->isCheckable()){
        QMessageBox question;
        question.setText("Вы согласны получить рейсы по всем видам транспорта?");
        question.setIcon(QMessageBox::Question);

        question.setStandardButtons(QMessageBox::Yes | QMessageBox::No);

        question.exec();
        return;

    }
}

void Widget::onAsk(){
    ask->show();
}

void Widget::onClearButton(){
    resultEdit->clear();
}