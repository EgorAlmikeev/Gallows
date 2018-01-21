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

    void displayGameWord(QString word);
    void letterButtonClicked(QWidget * button);

};

#endif // PLAYWIDGET_H
