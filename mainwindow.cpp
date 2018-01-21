#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    pCore = new GallowsCore;
    pPlayWidget = new PlayWidget;
    pWordInputWidget = new WordInputWidget;
    pMainStackedWidget = new QStackedWidget;

    setCentralWidget(pMainStackedWidget);

    pMainStackedWidget->addWidget(pPlayWidget);
    pMainStackedWidget->addWidget(pWordInputWidget);

    pMainStackedWidget->setCurrentWidget(pWordInputWidget);

    //connections setup
    connect(pWordInputWidget, SIGNAL(sendWordToCore(QString)), SLOT(startGame(QString)));
    connect(pPlayWidget, SIGNAL(makeStep(QString)), SLOT(makeCoreStep(QString)));

    //GUI changes for word input widget
    setGeometry(500, 300, 1, 1);
    pMainStackedWidget->setFixedHeight(200);
}

MainWindow::~MainWindow() {

}

void MainWindow::startGame(QString word) {
    pCore->setOriginalWord(word);
    pCore->gameInit();
    pPlayWidget->displayGameWord(pCore->getGameWord());

    //GUI changes for play widget
    setGeometry(500, 50, 1, 1);
    pMainStackedWidget->setFixedHeight(770);
    pMainStackedWidget->setCurrentWidget(pPlayWidget);
}

void MainWindow::makeCoreStep(QString letter) {
    pCore->makeStep(letter);
    pPlayWidget->displayGameWord(pCore->getGameWord());
}
