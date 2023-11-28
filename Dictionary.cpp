//
// Created by Insung Seo on 11/27/23.
//

#include <fstream>
#include <iostream>
#include "Dictionary.h"

Dictionary::Dictionary() {
    if (!loadDictionary("files/Dictionary.txt")) {
        std::cout << "files/Dictionary.txt" << " file not found" << std::endl;
    }
    else {
        loadDictionary("files/Dictionary.txt");
    }
}

bool Dictionary::loadDictionary(string fileName) {
    string line;
    char key;
    ifstream file;
    file.open(fileName);

    if (!file.is_open()) {
        return false;
    }

    // todo: load words to dictionary variable
    while (getline(file, line)) {
        key = line[0];
        dictionary[key].push_back(line);
    }
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
