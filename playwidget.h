#ifndef PLAYWIDGET_H
#define PLAYWIDGET_H

#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QSignalMapper>

class PlayWidget : public QWidget {
    Q_OBJECT


    QLabel        * pPictureLabel;
    QLineEdit     * pGameWordLineEdit;
    QGridLayout   * pButtonsGridLayout;
    QPushButton   * pLettersButtonsArray[33];
    QVBoxLayout   * pCentralVerticalLayout;
    QSignalMapper * pLettersSignalMapper;


public:
    explicit PlayWidget(QWidget *parent = nullptr);

signals:

    void makeStep(QString);

public slots:

    void display(QString word);
    void letterButtonClicked(QWidget * button);
    void setPicture(int attempts);

};

#endif // PLAYWIDGET_H
