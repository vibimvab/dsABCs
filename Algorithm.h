#pragma once
#include "Dictionary.h"
#include <vector>
#include <string>
#include <set>
#include <map>

std::set<std::string> getHighestWordsHeaps(const std::string& lettersInput, const Dictionary& dict);
void heapsAlgorithm(const int n, string& word, std::set<std::string>& result, const Dictionary& dict);