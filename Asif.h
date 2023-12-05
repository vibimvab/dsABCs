//
// Created by Emma Mitchell on 11/30/23.
//
//

#ifndef DSABCS_ASIF_H
#define DSABCS_ASIF_H
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
class Asif {    //a class that does combinations and then permutations 
private:    //all private methods 
    vector<vector<string>> AsifA(int num, const vector<string> &vec, Dictionary &d) {  //the asif algorithm
        //this algorithm takes in a vector of characters and the number that we want to use for combinations
        //references to Wikipedia.com and https://medium.com/codex/generating-combinations-efficiently-with-asifs-algorithm-d453e803893
        vector<vector<string>> finalList;   //will store all the combinations
        string firstVal;
        if (num == 0) {
            return {{}};
        }
        for (int i = 0; i <= vec.size() - num; ++i) {
            firstVal = vec[i];  //getting the first word
            auto combos = AsifA(num - 1, {vec.begin() + i + 1, vec.end()}, d); //recursive call
            for (auto &c: combos) {
                c.push_back(firstVal);
                finalList.push_back(c); //creating the final list
            }
        }
        return finalList;   //return the final list
    }
    vector<string> AsifWords(int num, const vector<string> &vec, Dictionary &d){    //method that is used to simplify the result from Asif A
        vector<vector<string>> vec2 = AsifA(num, vec, d);   //creating vec2
        vector<string> returnVec;   //this is the vector that is simplified by this function
        for (int i = 0; i < vec2.size() ; ++i) {
            string concat= "";
            for (int j = 0; j < vec2.at(i).size(); ++j) {
                concat = concat + vec2.at(i).at(j);
            }
            returnVec.push_back(concat);
        }
        return returnVec;   //returning the simplified vec
    }
    vector<string> permutationsOfAssif(const vector<string> &listToPermutate, Dictionary &d) {  //method that finds and creates permutations
        vector<string> permutationVector;   //vector of permutations 
        for (const string &originalString : listToPermutate) {  //this is the list of words that are just combinations
            string currentString = originalString; // Create a copy before sorting
            sort(currentString.begin(), currentString.end());   //sort before permutation
            do {
                permutationVector.push_back(currentString); //add to permutations
            } while (next_permutation(currentString.begin(), currentString.end())); //do the next permutations 
        }
        return permutationVector;       //return valid permutations 
    }
    bool aValidWord(string word, Dictionary &d) {   //a method to check if a word is valid 
        bool val = false;
        val= d.find(word);  //if in dictionary or not 
        return val;
    }
    map<int, vector<string>> finalReturn(map<int, vector<string>> &map1, int &highestValue, Dictionary &d){     //this method creates a map that just has a vector with the highest scoring words 
        map<int, vector<string>> :: iterator itr;   //to iterate over a map that has everything
        map<int, vector<string>> returnMap; //a map w just highscoring words
        int comparison = map1.begin()->first;   //will use this to compare 
        for (itr = map1.begin(); itr!=map1.end(); ++itr) {  //iterate over full map and condense it 
            if (itr->first>comparison){
                comparison=itr->first;
                highestValue = comparison;
            }
        }
        returnMap[comparison] = map1[comparison];
        return returnMap;   //return condensed map 
    }
    vector<string> isAWordValid(const vector<string> &listToPermutate, Dictionary &d){  //going through a lot of the words and seeing if they are in the dict
        vector<string> permutations = permutationsOfAssif(listToPermutate, d);  //taking a vector and doing permutations
        vector<string> validWords;  //the return vector of valid words
        for (int i = 0; i < permutations.size(); ++i) {     //checking to see if a word is valid 
            bool valid = aValidWord(permutations.at(i), d);     //running a checker function
            if (valid){
                validWords.push_back(permutations.at(i));
            }
        }
        return validWords;
    }
    map<int, vector<string>> wordValues(vector<string> &wordsInTheDictionary, int &highestValue, Dictionary &d){
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
        correctVals= finalReturn(mapOfScrabble, highestValue, d);
        return correctVals;
    }
    vector<string> allAsif(const vector<string> &vec, Dictionary &d){  //this is the function that will be called
        vector<string> finalList;   //list of all combos of the letters
        vector<string> iterator;    //iterator vector
        int r= vec.size();  //number of scrabble tiles
        while (r>0){    //while there are scrabble tiles
            iterator = AsifWords(r, vec, d);
            for (int i = 0; i < iterator.size(); ++i) {
                finalList.push_back(iterator.at(i));
            }
            iterator.clear();
            r--;
        }
        vector<string> permutationOfFinalList;  //then permutating through every combo
        permutationOfFinalList= isAWordValid(finalList, d);    //will return only the permutations found in the dictionary
        int highestValue;   //finding the word with the highest score 
        map<int, vector<string>> finalResult = wordValues(permutationOfFinalList, highestValue, d); //will return a map of a score and the highest score 
        vector<string> vector1;
        vector1 = finalResult[highestValue];
        return vector1; //return a vector of all words that have the best score 
    }
public: //the method called in main 
    set<string> AsifCallFunction(string &s, Dictionary &d){ //this is the call function that is helpful in main
        string iter="";     //string that is sent in
        vector<string> concat;  //a vector of all of the chars (potential scrabble letters)
        for (int i = 0; i < s.length(); ++i) {  //creating the vector
            iter = s.substr(i,1);
            concat.push_back(iter);
        }
        vector<string> ret = allAsif(concat, d);    //calling the allAsif method
        set<string> sets;   //set that will be sent to main
        for (int i = 0; i < ret.size(); ++i) {  //adding to the set
            sets.insert(ret.at(i));
        }
        return sets;    //sending the set to main
    }

};


#endif //DSABCS_ASIF_H
