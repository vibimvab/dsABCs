//
// Created by Insung Seo on 11/27/23.
//

#ifndef DATASTRUCTURES_DICTIONARY_H
#define DATASTRUCTURES_DICTIONARY_H

#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Dictionary {
private:
    // group the words by its starting letter
    map<char, set<string>> dictionary;

    bool loadDictionary(const string& fileName);

public:
    // constructor
    Dictionary();

    bool find(const string& word) const;
};


#endif //DATASTRUCTURES_DICTIONARY_H
