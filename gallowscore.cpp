#include "gallowscore.h"

void GallowsCore::gameInit() {
    attempts = 9;
    for (int i = 0; i < originalWord.length(); ++i)
        gameWord.append( originalWord.at(i) == " " ? " " : "_" );
    usedLetters.clear();
}

QString GallowsCore::makeStep(QString letter) {

    letter = letter.toLower();

    if (usedLetters.contains(letter))
        throw LetterAlreadyUsedException();
    else usedLetters.append(letter);

    if (originalWord.contains(letter))
        for (int i = 0; i < originalWord.length(); ++i) {
            if (originalWord.at(i) == letter)
                gameWord.replace(i, 1, letter);
        }
    else
        --attempts;

    return gameWord;
}

QString GallowsCore::getUsedLetters() {
    return usedLetters;
}

QString GallowsCore::getGameWord() {
    return gameWord;
}

int GallowsCore::getAttempts() {
    return attempts;
}

void GallowsCore::setOriginalWord(QString word) {
    originalWord = word.toLower();
}
