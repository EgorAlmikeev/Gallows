#ifndef WORDINPUTWIDGET_H
#define WORDINPUTWIDGET_H

#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

class WordInputWidget : public QWidget {
    Q_OBJECT

    QLabel      * pLabel;
    QLineEdit   * pWordLineEdit;
    QPushButton * pNextButton;
    QVBoxLayout * pCentralVerticalLayout;

public:
    explicit WordInputWidget(QWidget *parent = nullptr);

signals:

    void sendWordToCore(QString);

public slots:

    void wordCheckout();

};

#endif // WORDINPUTWIDGET_H
