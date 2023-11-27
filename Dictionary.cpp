//
// Created by Insung Seo on 11/27/23.
//

#include <fstream>
#include <iostream>
#include "Dictionary.h"

Dictionary::Dictionary() {
    std::string fileName = "words_alpha.txt";
    if (!loadDictionary(fileName)) {
        std::cout << fileName << " file not found" << std::endl;
    }
}

bool Dictionary::loadDictionary(string fileName) {
    ifstream file;
    file.open(fileName);

    if (!file.is_open()) {
        return false;
    }

    // todo: load words to dictionary variable

    return true;
}

bool Dictionary::find(const string& word) {
    // todo: implement
    return false;
}

vector<string> Dictionary::find(const vector<string>& words) {
    // todo: implement
    return vector<string>();
}
