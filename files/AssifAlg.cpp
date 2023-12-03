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
using namespace std;


struct AssifAlg {
public:

    vector<string> vec2;
    vector<string> permutationVector;   //vector that will permutate over every combination


    bool aValidWord(string word) {
        //for the list of words check and see if this word matches
        return true;
    }

  vector<string> permutationsOfAssif(const vector<string> &listToPermutate) {
        vector<string> permutationVector;
        vector<int> indices(listToPermutate.size());
        iota(indices.begin(), indices.end(), 0);
        do {
            string pString;
            for (int i : indices) {
                pString = pString+ listToPermutate[i];
            }
            permutationVector.push_back(pString);
        } while (next_permutation(indices.begin(), indices.end()));
        return permutationVector;
    }
    vector<vector<string>> Assif(int num, const vector<string> &vec) {
        vector<vector<string>> finalList;
        string firstVal;
        if (num == 0) {
            return {{}};
        }
        for (int i = 0; i <= vec.size() - num; ++i) {
            firstVal = vec[i];  //getting the first word
            auto combos = Assif(num - 1, {vec.begin() + i + 1, vec.end()}); //recursive call
            for (auto &c: combos) {
                c.push_back(firstVal);
                finalList.push_back(c); //creating the final list
            }
        }
        return finalList;   //return the final list
    }
};
