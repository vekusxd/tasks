
#include "../include/askwidget.hpp"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include "../include/httpManager.hpp"


AskWidget::AskWidget(QWidget *parent) : QWidget(parent){
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QHBoxLayout *hLayout = new QHBoxLayout;

    askEdit = new QLineEdit;
    askEdit->setPlaceholderText("название");

    QVBoxLayout *forButtons = new QVBoxLayout;

    askFindButton = new QPushButton("&Найти");
    clearButton = new QPushButton("&Очистить");

    forButtons->addWidget(askFindButton);
    forButtons->addWidget(clearButton);


    hLayout->addWidget(askEdit);

    mainLayout->addLayout(hLayout);

    mainLayout->addLayout(forButtons);

    askResultEdit = new QTextEdit;
    askResultEdit->setReadOnly(true);

    mainLayout->addWidget(askResultEdit);

    tempObject = GeocordObject();

    connect(clearButton, &QPushButton::clicked, this, &AskWidget::onClearButton);
    connect(askFindButton, &QPushButton::clicked, this, &AskWidget::onAskFindButton);
}


void AskWidget::onClearButton(){
    askResultEdit->clear();
}


void AskWidget::onAskFindButton(){
    Cords cord = httpManager::getCords(askEdit->text());

    QString result = httpManager::getNearStations(cord);

    askResultEdit->setText(result);
}