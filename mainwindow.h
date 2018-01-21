#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

#include "playwidget.h"
#include "gallowscore.h"
#include "wordinputwidget.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

    GallowsCore     * pCore;
    PlayWidget      * pPlayWidget;
    WordInputWidget * pWordInputWidget;
    QStackedWidget  * pMainStackedWidget;

    bool gameStopped = false;

public:

    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots :

    void startGame(QString word);
    void makeCoreStep(QString letter);
    void stopGame();
};

#endif // MAINWINDOW_H
