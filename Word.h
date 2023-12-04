#ifndef DATASTRUCTURES_WORD_H
#define DATASTRUCTURES_WORD_H

#include <map>
#include <string>

class Word {
    const std::map<char, int> letterScore = {
            // 1 point
            {'a', 1},
            {'e', 1},
            {'i', 1},
            {'o', 1},
            {'u', 1},
            {'l', 1},
            {'n', 1},
            {'s', 1},
            {'t', 1},
            {'r', 1},

            // 2 points
            {'d', 2},
            {'g', 2},

            // 3 points
            {'b', 3},
            {'c', 3},
            {'m', 3},
            {'p', 3},

            // 4 points
            {'f', 4},
            {'h', 4},
            {'v', 4},
            {'w', 4},
            {'y', 4},

            // 5 points
            {'k', 5},

            // 8 points
            {'j', 8},
            {'x', 8},

            // 10 points
            {'q', 10},
            {'z', 10}
    };

public:
    int evaluateWord(const std::string& word);
};


#endif //DATASTRUCTURES_WORD_H
