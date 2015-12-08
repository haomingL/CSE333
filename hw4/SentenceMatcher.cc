#include "SentenceMatcher.h"

#include <string>
#include <iostream>

#define IS_START 0
#define IS_CHAR 1
#define IS_STAR 2
#define IS_PLUS 3
#define MATCH 257
#define SPLIT 256

using namespace std;

SentenceMatcher::SentenceMatcher(string &regex) {
	string::iterator it;
	int prevState = IS_START;
	for (it = regex.begin(); it != regex.end(); it++) {
		switch (*it) {
			case '*': {
				shared_ptr<State> ptr = make_shared<State>(State(SPLIT));
				shared_ptr<State> prev = states_[states_.size() - 1];

				ptr->out1_ = prev;
				prev->out2_ = ptr;

				if (states_.size() > 1) {
					states_[states_.size() - 2]->out1_ = ptr;
				}
				if (prevState == IS_STAR) {
					states_[states_.size() - 3]->out2_ = ptr;
					cout << "lalala" << endl;
				}
				states_.insert(states_.begin() + states_.size() - 1, ptr);
				prevState = IS_STAR;
				break;
			}
			case '+': {
				// Don't need to check prevState here since we will only have IS_CHAR
				shared_ptr<State> ptr = make_shared<State>(State(SPLIT));
				states_.back()->out1_ = ptr;
				shared_ptr<State> temp(states_.back());
				weak_ptr<State> wptr = temp;
				ptr->out2_ = wptr;
				states_.push_back(ptr);
				prevState= IS_PLUS;
				break;
			}
			case '\\': {
				// Go to the default state
				it++;
			}
			default: {
				shared_ptr<State> ptr = make_shared<State>(State(*it));
				if (prevState == IS_START) {
					states_.push_back(ptr);
				} else {
					states_.back()->out1_ = ptr;
					if (prevState == IS_STAR) {
						states_[states_.size() - 2]->out2_ = ptr;
					}
					states_.push_back(ptr);
				}
				if (prevState == IS_STAR && it + 1 != regex.end() && *(it + 1) == '*') {
					prevState = IS_STAR; // If this one is a char before a *, keep the prevState as IS_STAR
				} else {
					prevState = IS_CHAR; // If this one is not a char before a *, make the prevState as IS_CHAR
				}
				break;
			}
		}
	}
	
	// Append the last match state
	shared_ptr<State> ptr = make_shared<State>(State(MATCH));
	if (prevState != IS_START) states_.back()->out1_ = ptr;
	if (prevState == IS_STAR) {
		states_[states_.size() - 2]->out2_ = ptr;
	}
	states_.push_back(ptr);
}

SentenceMatcher::~SentenceMatcher() {

}

bool SentenceMatcher::isMatch(string &str) {
	string::iterator it;
	vector<State> cstates;
	vector<State> nstates;
	cstates.push_back(*(states_.front()));
	for (unsigned int i = 0; i < cstates.size(); i++) {
		State s = cstates[i];
		if (str.size() == 0) cout << s.c_ << endl;
		if (s.match(SPLIT)) {
			auto spt = s.out2_.lock();
			cstates.push_back(*spt);
			cstates.push_back(*s.out1_);
		} else if (cstates[i].match(MATCH)) {
			cstates.clear();
			return true;
		}
	}	
	for (it = str.begin(); it != str.end(); it++) {
		for (unsigned int i = 0; i < cstates.size(); i++) {
			State s = cstates[i];
			if (s.match(*it)) {
				nstates.push_back(*(s.out1_));
				if (auto spt = s.out2_.lock()) {
					nstates.push_back(*spt);
				}
			} else if (s.match(SPLIT)) {
				auto spt = s.out2_.lock();
			    cstates.push_back(*spt);
				cstates.push_back(*s.out1_);
			} else if (s.match(MATCH)) {
				return true;
			}		
		}
		cstates = nstates;
		nstates.clear();
	}
	for (unsigned int i = 0; i < cstates.size(); i++) {
		if (cstates[i].match(MATCH)) {
			cstates.clear();
			return true;
		}
	}
	cstates.clear();
	return false;
}








