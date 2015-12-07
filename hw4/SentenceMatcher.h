#ifndef SENTENCE_MATCHER_H
#define SENTENCE_MATCHER_H

#include <string>
#include <vector>
#include "State.h"

class SentenceMatcher {
	private:
		vector<shared_ptr<State>> states_;

	public:
		SentenceMatcher(string &regex);
		~SentenceMatcher();
		bool isMatch(string &str);
};

#endif // SENTENCE_MATCHER_H