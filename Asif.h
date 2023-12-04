//
// Created by Emma Mitchell on 11/30/23.
//

#ifndef DSABCS_DATASTRUCT_H
#define DSABCS_DATASTRUCT_H
#include <iostream>
#include "map"
#include <vector>
#include "set"
#include "sstream"
#include "math.h"
#include "array"
#include <string>
#include "algorithm"
#include "numeric"
#include "Dictionary.h"
#include "Word.h"
using namespace std;


class DataStruct {
private:
    vector<vector<string>> Asif(int num, const vector<string> &vec) {  //the asif algorithm
        //this algorithm takes in a vector of characters and the number that we want to use for combinations
        //references to Wikipedia.com and https://medium.com/codex/generating-combinations-efficiently-with-asifs-algorithm-d453e803893
        vector<vector<string>> finalList;   //will store all the combinations
        string firstVal;
        if (num == 0) {
            return {{}};
        }
        for (int i = 0; i <= vec.size() - num; ++i) {
            firstVal = vec[i];  //getting the first word
            auto combos = Asif(num - 1, {vec.begin() + i + 1, vec.end()}); //recursive call
            for (auto &c: combos) {
                c.push_back(firstVal);
                finalList.push_back(c); //creating the final list
            }
        }
        return finalList;   //return the final list
    }
    vector<string> AsifWords(int num, const vector<string> &vec){
        vector<vector<string>> vec2 = Asif(num, vec);
        vector<string> returnVec;
        for (int i = 0; i < vec2.size() ; ++i) {
            string concat= "";
            for (int j = 0; j < vec2.at(i).size(); ++j) {
                concat = concat + vec2.at(i).at(j);
            }
            returnVec.push_back(concat);
        }
        return returnVec;
    }
    vector<string> permutationsOfAssif(const vector<string> &listToPermutate) {
        vector<string> permutationVector;
        for (const string &originalString : listToPermutate) {
            string currentString = originalString; // Create a copy before sorting
            sort(currentString.begin(), currentString.end());

            do {
                permutationVector.push_back(currentString);
            } while (next_permutation(currentString.begin(), currentString.end()));
        }
        return permutationVector;
    }
    bool aValidWord(string word) {
        bool val = false;
        Dictionary d;
        val= d.find(word);
        return val;
    }
    map<int, vector<string>> finalReturn(map<int, vector<string>> &map1, int &highestValue){
        map<int, vector<string>> :: iterator itr;
        map<int, vector<string>> returnMap;
        int comparison = map1.begin()->first;
        for (itr = map1.begin(); itr!=map1.end(); ++itr) {
            if (itr->first>comparison){
                comparison=itr->first;
                highestValue = comparison;
            }
        }
        returnMap[comparison] = map1[comparison];
        return returnMap;
    }
    vector<string> isAWordValid(const vector<string> &listToPermutate){
        vector<string> permutations = permutationsOfAssif(listToPermutate);
        vector<string> validWords;
        for (int i = 0; i < permutations.size(); ++i) {
            bool valid = aValidWord(permutations.at(i));
            if (valid){
                validWords.push_back(permutations.at(i));
            }
        }
    }
    map<int, vector<string>> wordValues(vector<string> &wordsInTheDictionary, int &highestValue){
        int value=0;
        map<int, vector<string>> mapOfScrabble;
        map<int, vector<string>> correctVals;
        Word w;
        for (int i = 0; i < wordsInTheDictionary.size(); ++i) {
            string word = wordsInTheDictionary.at(i);
            value = w.evaluateWord(word);
            if (mapOfScrabble.count(value)){
                mapOfScrabble.at(value).push_back(word);
            } else
            {
                mapOfScrabble[value].push_back(word);
            }
        }
        correctVals= finalReturn(mapOfScrabble, highestValue);
        return correctVals;
    }
public:


    vector<string> allAsif(const vector<string> &vec){  //this is the function that will be called
        vector<string> finalList;
        vector<string> iterator;
        int r= vec.size();
        while (r>0){
            iterator = AsifWords(r, vec);
            for (int i = 0; i < iterator.size(); ++i) {
                finalList.push_back(iterator.at(i));
            }
            iterator.clear();
            r--;
        }
        vector<string> permutationOfFinalList;
        permutationOfFinalList= isAWordValid(finalList);    //will return only the permutations found in the dictionary
        int highestValue;
        map<int, vector<string>> finalResult = wordValues(permutationOfFinalList, highestValue);
        vector<string> vector1;
        vector1 = finalResult[highestValue];
        return vector1;
    }





};


#endif //DSABCS_DATASTRUCT_H
