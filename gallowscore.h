#ifndef GALLOWSCORE_H
#define GALLOWSCORE_H


#include <iostream>
#include <QString>

using namespace std;

class GallowsCore {

    QString originalWord;
    QString gameWord;
    QString usedLetters;

    int attempts;

public :

//    class GallowsCoreException { public : GallowsCoreException(QString what) : what(what) {} QString what; };
    class LetterAlreadyUsedException {};

    int getAttempts();
    void gameInit();
    void setOriginalWord(QString word);
    QString getGameWord();
    QString getUsedLetters();
    QString getOriginalWord();
    QString makeStep(QString letter);
};

#endif // GALLOWSCORE_H
