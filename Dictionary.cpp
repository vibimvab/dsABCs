#include <fstream>
#include <iostream>
#include "Dictionary.h"

Dictionary::Dictionary() {
    if (!loadDictionary("files/Dictionary.txt")) { // replace the string to "../files/Dictionary.txt" to run with CMake
        std::cout << "files/Dictionary.txt" << " file not found" << std::endl;
    } // else loadDictionary("files/Dictionary.txt") is unnecessary already ran in if statement
}

bool Dictionary::loadDictionary(const string& fileName) {
    std::string line;
    char key;
    ifstream file;
    file.open(fileName);

    if (!file.is_open()) {
        return false;
    }

    // load words to dictionary variable
    while (getline(file, line)) {
        key = line[0];
        this->dictionary[key].insert(line);
    }
    return true; 
}

bool Dictionary::find(const string& word) const {
    string wordLocal = word;
    std::transform(wordLocal.begin(), wordLocal.end(), wordLocal.begin(), ::toupper);
    char firstLetter = wordLocal.at(0);
    return this->dictionary.at(firstLetter).find(wordLocal) != this->dictionary.at(firstLetter).end();
}
