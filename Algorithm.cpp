#include "Algorithm.h"

std::set<std::string> getHighestWordsHeaps(const std::string& lettersInput, const Dictionary& dict) {
//    if (lettersInput.empty()) {
//        return {};
//    }

    std::string letters(lettersInput.begin(), lettersInput.end()); // local copy of letters to pass to functions
    std::set<std::string> result; // return set

    std::map<int, std::set<std::string>*> stack; // not actually a stack but works similarly
    // iteration starts with word with all letters
    Word letterSet;
    int score = letterSet.evaluateWord(letters);
    bool wordFound = false;
    std::string tempWord; // copy of word
    stack.emplace(score, new std::set<std::string>());
    stack.at(score)->emplace(letters);

    while (!wordFound) {
        // for each iteration, find the highest scoring word in dictionary
        // if the word is found, set wordFound. iterate only with the words with the same score
        score = stack.rbegin()->first; // starting from back (the highest scoring letter set)
        if (score == 0) break; // if the stack is empty except for empty string

        for (const std::string& word: *stack.at(score)) {
            tempWord = word;
            heapsAlgorithm((int)word.size(), tempWord, result, dict);
            if (!result.empty()) // if a word exists in dictionary
                wordFound = true;

            if (!wordFound) {
                // add next words to stack, no need to add if a word is found
                std::string wordToAdd;
                for (int i = 0; i < word.size(); i++) {
                    auto newWord = word.substr(0, i) + word.substr(i+1, word.size()-i-1);
                    auto newWordScore = letterSet.evaluateWord(newWord);
                    if (stack.find(newWordScore) == stack.end()) {
                        // key not found (word with that score does not exist in stack)
                        stack.emplace(newWordScore, new std::set<std::string>());
                    }

                    stack.at(newWordScore)->emplace(newWord);
                }
            }
        }

        stack.erase(score);
    }

    return result;
}

void heapsAlgorithm(const int n, string& word, std::set<std::string>& result, const Dictionary& dict) {
    // referred to wikipedia: https://en.wikipedia.org/wiki/Heap%27s_algorithm
    if (n == 1) {
        if (dict.find(word))
            result.emplace(word);
        return;
    }
    else {
        // Generate permutations with n-th unaltered
        // Initially n = length(word)
        heapsAlgorithm(n-1, word, result, dict);

        // Generate permutations for n-th swapped with each n-1 initial
        for (int i = 0; i < n-1; i++) {
            // Swap choice dependent on parity of n (even or odd)
            if (n % 2 == 0) {
                std::swap(word[i], word[n-1]);
            } else {
                std::swap(word[0], word[n-1]);
            }
            heapsAlgorithm(n-1, word, result, dict);
        }
    }
}
