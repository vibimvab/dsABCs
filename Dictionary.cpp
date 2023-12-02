#include <fstream>
#include <iostream>
#include "Dictionary.h"

Dictionary::Dictionary() {
    if (!loadDictionary("files/Dictionary.txt")) {
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
    return this->dictionary.at(word.at(0)).find(word) != this->dictionary.at(word.at(0)).end();
}
