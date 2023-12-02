#include "Word.h"

int Word::evaluateWord(const std::string& word) {
    int score = 0;
    for (char c: word) {
        score += letterScore.at(c);
    }

    return score;
}
