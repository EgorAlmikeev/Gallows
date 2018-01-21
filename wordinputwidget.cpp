#include "wordinputwidget.h"

WordInputWidget::WordInputWidget(QWidget *parent) : QWidget(parent) {

    pCentralVerticalLayout = new QVBoxLayout;
    pCentralVerticalLayout->setAlignment(Qt::AlignCenter);
    pCentralVerticalLayout->setMargin(50);
    setLayout(pCentralVerticalLayout);

    pLabel = new QLabel("Загадайте слово или словосочетание\n(максимум 20 символов)");
    pLabel->setAlignment(Qt::AlignCenter);
    pLabel->setFont(QFont("Arial", 14));
    pCentralVerticalLayout->addWidget(pLabel);

    pWordLineEdit = new QLineEdit;
    pWordLineEdit->setMaxLength(20);
    pCentralVerticalLayout->addWidget(pWordLineEdit);

    pNextButton = new QPushButton("Next");
    pCentralVerticalLayout->addWidget(pNextButton);

    connect(pNextButton, SIGNAL(clicked()), SLOT(wordCheckout()));
}

void WordInputWidget::wordCheckout() {
    QString word = pWordLineEdit->text();

    if (word.contains(QRegExp("^[А-яё ]+$"))) {

        for (int i = 0; i < word.length() - 1; ++i)
            if (word.at(i) == ' ' && word.at(i + 1) == ' ') {
                word.remove(i, 1);
                i -= 2;
            }

        emit sendWordToCore(word.trimmed().toLower());
    }
    else
        pLabel->setText("Слово не принято.\nВвод может содержать только буквы русского алфавита и пробелы.");
}
