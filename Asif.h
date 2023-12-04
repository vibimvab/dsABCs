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

public:
    bool aValidWord(string word) {
        Dictionary d;

        return true;
    }
  vector<string> permutationsOfAssif(const vector<string> &listToPermutate) {   //this is my method to permute after a combination was done
        vector<string> permutationVector;   //will return a vector of the permutations
        vector<int> indices(listToPermutate.size());    //we will store a vector of indices of the permutation size
        iota(indices.begin(), indices.end(), 0);    //we will get these indices in sequence
        do {    //a do while loop to create the permutations
            string pString;     //a blank string
            for (int i : indices) {
                pString = pString+ listToPermutate[i];  //append to the string
            }
            permutationVector.push_back(pString);   //add to the vector
        } while (next_permutation(indices.begin(), indices.end()));     //while you can still permutate
        return permutationVector;   //will return the permutations
    }
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
        return finalList;
    }
    

};
