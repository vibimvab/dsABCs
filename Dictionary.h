//
// Created by Insung Seo on 11/27/23.
//

#ifndef DATASTRUCTURES_DICTIONARY_H
#define DATASTRUCTURES_DICTIONARY_H

#include <string>
#include <vector>
#include <map>

using namespace std;

class Dictionary {
private:
    // group the words by its starting letter
    map<char, vector<string>> dictionary;

    bool loadDictionary(string fileName);

public:
    // constructor
    Dictionary();

    // pass a word
    bool find(const string& word);
    // pass sorted vector of words
    // this function might be more useful than "bool find(string)"
    vector<string> find(const vector<string>& words);
};


#endif //DATASTRUCTURES_DICTIONARY_H
