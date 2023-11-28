#include "Word.h"
#include "Dictionary.h"
#include <vector>
#include <string>
#include <set>
#include <map>

std::set<std::string> getHighestWords(const std::string& letters, const Dictionary& dict);
void heapsAlgorithm(const string& inputLetters, std::set<std::string>& result);


std::set<std::string> getHighestWords(const std::string& letters, const Dictionary& dict) {
    std::set<std::string> result;

    std::map<int, std::set<std::string>> stack; // not actually a stack but works similar

    // iteration starts with word with all letters
    int score = Word::evaluateWord(letters);
    bool flag = false;
    stack.emplace(score, std::set<std::string>());
    stack.at(score).emplace(letters);

    while (!stack.empty() && !flag) {
        // for each iteration, find the highest scoring word in dictionary
        // if the word is found, set flag. iterate only with the words with the same score
        score = stack.rbegin()->first; // starting from back (the highest score)
        for (std::string word: stack.at(score)) {
            heapsAlgorithm(word, result);
            if (!result.empty()) { // if a word is found
                flag = true;
            }

            if (!flag) {
                // todo: add next word
            }
        }

        stack.erase(score);
    }

    return result;
}

std::string swap(std::string originalStr, int index1, int index2) {
    return "";
}

std::vector<std::string> heapsAlgorithm(const std::vector<char>& inputLetters) {
    std::string letters(inputLetters.begin(), inputLetters.end());

}