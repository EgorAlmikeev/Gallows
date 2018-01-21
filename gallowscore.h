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

    void setOriginalWord(QString word);

    QString getGameWord();

    int getAttempts();

    QString getUsedLetters();

    void gameInit();

    QString makeStep(QString letter);
};

#endif // GALLOWSCORE_H
