// Haoming Liu
// 1332998
// haoming@uw.edu

#include "TokenCounter.h"

using namespace std;

TokenCounter::TokenCounter(const vector<std::string> &tokenCollection) {
	sorted = false;
	for (unsigned int i = 0; i < tokenCollection.size(); i++) {
		string word = tokenCollection[i];
		words[word] = words.find(word) != words.end() ? ++words[word] : 1;
	}
}
  
// We declare the destructor in case some implementation requires one
TokenCounter::~TokenCounter() {
	words.clear();
}

// Returns the N most frequently occuring tokens in the constructor arg vector
vector<pair<string,int>> TokenCounter::getTop(int N) {
	if (!sorted) { 
		sorted_words = sort();
	}
	vector<pair<string,int>> result (sorted_words.begin(), sorted_words.begin() + N);
	return result;
}

vector<pair<string,int>> TokenCounter::sort() {
	vector<pair<string,int>> result;
	for (auto it = words.cbegin(); it != words.cend(); it++) {
		pair<string, int> element ((*it).first, (*it).second);
		bool inserted = false;
		auto begin = result.begin();
		for (unsigned int i = 0; i < result.size(); i++) {
			if (result[i].second < element.second) {
				result.insert(begin + i, element);
				inserted = true;
				break;
			}
		}
		if (!inserted) result.push_back(element);
	}
	return result;
}