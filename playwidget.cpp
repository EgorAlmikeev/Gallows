#include "playwidget.h"

PlayWidget::PlayWidget(QWidget *parent) : QWidget(parent) {
    //central layout setup
    pCentralVerticalLayout = new QVBoxLayout;
    setLayout(pCentralVerticalLayout);

    pCentralVerticalLayout->setStretch(0, 8);
    pCentralVerticalLayout->setStretch(1, 1);
    pCentralVerticalLayout->setStretch(3, 2);

    //pictures area setup
    pPictureLabel = new QLabel;
    pPictureLabel->setFrameStyle(QFrame::WinPanel);
    pCentralVerticalLayout->addWidget(pPictureLabel);

    //game word text edit setup
    pGameWordLineEdit = new QLineEdit;
    pGameWordLineEdit->setReadOnly(true);
    pGameWordLineEdit->setText("S_M_L_ T_X_");
    pGameWordLineEdit->setFont(QFont("Courier New", 50));
    pGameWordLineEdit->setAlignment(Qt::AlignCenter);
    pCentralVerticalLayout->addWidget(pGameWordLineEdit);

    //buttons grid layout setup
    pButtonsGridLayout = new QGridLayout;
    pCentralVerticalLayout->addLayout(pButtonsGridLayout);

    //letters buttons setup
    pLettersSignalMapper = new QSignalMapper;

    QString alphabet [] = {
        "А", "Б", "В", "Г", "Д", "Е", "Ё", "Ж", "З", "И", "Й",
        "К", "Л", "М", "Н", "О", "П", "Р", "С", "Т", "У", "Ф",
        "Х", "Ц", "Ч", "Ш", "Щ", "Ъ", "Ы", "Ь", "Э", "Ю", "Я"
    };

    QPushButton * pNewButton;

    for (int j = 0; j < 3; ++j)
        for (int i = j * 11; i < (j + 1) * 11; ++i) {
            pNewButton = new QPushButton(alphabet[i]);

            pLettersSignalMapper->setMapping(pNewButton, pNewButton);
            connect(pNewButton, SIGNAL(clicked(bool)), pLettersSignalMapper, SLOT(map()));

            pLettersButtonsArray[i] = pNewButton;
            pButtonsGridLayout->addWidget(pNewButton, j, i - j * 11);
        }

    connect(pLettersSignalMapper, SIGNAL(mapped(QWidget *)), SLOT(letterButtonClicked(QWidget *)));
}

void PlayWidget::displayGameWord(QString word) {
    pGameWordLineEdit->setText(word);
}

void PlayWidget::letterButtonClicked(QWidget * button) {
    button->setEnabled(false);
    emit makeStep(((QPushButton *) button)->text());
}
