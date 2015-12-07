#ifndef SENTENCE_MATCHER_H
#define SENTENCE_MATCHER_H

#include <string>
#include "State.h"

class SentenceMatcher {
	private:
		State start_;

	public:
		SentenceMatcher(string &regex);
		~SentenceMatcher();
		bool isMatch(string &str);
};

#endif // SENTENCE_MATCHER_H