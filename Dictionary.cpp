//
// Created by Insung Seo on 11/27/23.
//

#include <fstream>
#include <iostream>
#include "Dictionary.h"

Dictionary::Dictionary() {
    ifstream file;
    file.open("words_alpha.txt");

    if (!file.is_open()) {
        std::cout << "words_alpha.txt file not found" << std::endl;
    }
    else {
        
    }
}