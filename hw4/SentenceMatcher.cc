#include "SentenceMatcher.h"

#include <string>
#include <iostream>
#include <vector>

#define IS_START 0
#define IS_CHAR 1
#define IS_STAR 2
#define IS_PLUS 3
#define MATCH 257
#define SPLIT 256

using namespace std;

SentenceMatcher::SentenceMatcher(string &regex) : start_(-1) {
	string::iterator it;
	vector<State> states;
	int prevState = IS_START;
	for (it = regex.begin(); it != regex.end(); it++) {
		switch (*it) {
			case '*': {
				State s(SPLIT);
				State prev = states[states.size() - 1];
				states.pop_back();

				shared_ptr<State> char_ptr(&prev);
				s.patch1(char_ptr);
				weak_ptr<State> wptr = char_ptr;
				prev.patch2(wptr);

				if (!states.empty()) {
					shared_ptr<State> ptr(&s);
					states.back().patch1(ptr);
				}
				states.push_back(s);
				states.push_back(prev);
				prevState = IS_STAR;
				break;
			}
			case '+': {
				State s(SPLIT);
				shared_ptr<State> ptr(&s);
				states.back().patch1(ptr);
				shared_ptr<State> temp(&(states.back()));
				weak_ptr<State> wptr = temp;
				s.patch2(wptr);
				states.push_back(s);
				prevState= IS_PLUS;
				break;
			}
			case '\\': {
				it++;
			}
			default: {
				State s((int)*it);
				if (prevState == IS_START) {
					states.push_back(s);
					break;
				}
				shared_ptr<State> ptr(&s);
				states.back().patch1(ptr);
				if (prevState == IS_STAR) {
					weak_ptr<State> wptr = ptr;
					states[states.size() - 2].patch2(wptr);
				}
				states.push_back(s);
				prevState = IS_CHAR;
				break;
			}
		}
	}
	
	// Append the last match state
	State s(MATCH);
	shared_ptr<State> ptr(&s);
	states.back().patch1(ptr);
	if (prevState == IS_STAR) {
		weak_ptr<State> wptr = ptr;
		states[states.size() - 2].patch2(wptr);
	}
	states.push_back(s);
	start_ = states.front();
}

SentenceMatcher::~SentenceMatcher() {
	
}

bool SentenceMatcher::isMatch(string &str) {
	string::iterator it;
	vector<State> cstates;
	vector<State> nstates;
	cstates.push_back(start_);
	for (it = str.begin(); it != str.end(); it++) {
		while(!cstates.empty()) {
			State s = cstates.back();
			cstates.pop_back();
			if (s.match(*it)) {
				if (s.out1_) nstates.push_back(*(s.out1_));
				if (auto spt = s.out2_.lock()) nstates.push_back(*spt);
			} else if (s.match(SPLIT)) {
				auto spt = s.out2_.lock();
				cstates.push_back(*spt);
				cstates.push_back(*s.out1_);
			}
		}
		vector<State> temp = cstates;
		cstates = nstates;
		nstates = temp;
	}
	for (unsigned int i = 0; i < cstates.size(); i++) {
		if (cstates[i].match(MATCH)) return true;
	}
	return false;
}








