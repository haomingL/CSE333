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
				State *s = new State(SPLIT);
				shared_ptr<State> prev = states_[states_.size() - 1];

				s->out1_ = prev;
				shared_ptr<State> ptr = make_shared<State>(*s);
				prev->out2_ = ptr;

				if (states_.size() > 1) {
					states_[states_.size() - 2]->out1_ = ptr;
				}
				states_.insert(states_.begin() + states_.size() - 1, ptr);
				prevState = IS_STAR;
				break;
			}
			case '+': {
				State *s = new State(SPLIT);
				shared_ptr<State> ptr(s);
				states_.back()->out1_ = ptr;
				shared_ptr<State> temp(states_.back());
				weak_ptr<State> wptr = temp;
				s->out2_ = wptr;
				states_.push_back(ptr);
				prevState= IS_PLUS;
				break;
			}
			case '\\': {
				it++;
			}
			default: {
				State *s = new State(*it);
				if (prevState == IS_START) {
					states_.push_back(make_shared<State>(*s));
				} else {
					shared_ptr<State> ptr(s);
					states_.back()->out1_ = ptr;
					if (prevState == IS_STAR) {
						states_[states_.size() - 2]->out2_ = ptr;
					}
					states_.push_back(ptr);
				}
				prevState = IS_CHAR;
				break;
			}
		}
	}
	
	// Append the last match state
	State *s = new State(MATCH);
	shared_ptr<State> ptr(s);
	states_.back()->out1_ = ptr;
	if (prevState == IS_STAR) {
		states_[states_.size() - 2]->out2_ = ptr;
	}
	states_.push_back(ptr);
	// for (unsigned int i = 0; i < states_.size(); i++) {
	// 	cout << states_[i]->c_ << endl;
	// 	shared_ptr<State> current = states_[i];
	// 	shared_ptr<State> current1 = current->out1_;
	// 	weak_ptr<State> current2;
	// 	if (current1) cout << current1->c_ << endl;
	// 	if (auto apt = current->out2_.lock()) {
	// 		cout << apt->c_ << endl;
	// 	}
	// 	cout << endl;
	// }
}

SentenceMatcher::~SentenceMatcher() {
	
}

bool SentenceMatcher::isMatch(string &str) {
	// cout << "Match !!!" << endl;
	// for (unsigned int i = 0; i < states_.size(); i++) {
	// 	cout << states_[i]->c_ << endl;
	// 	shared_ptr<State> current = states_[i];
	// 	shared_ptr<State> current1 = current->out1_;
	// 	weak_ptr<State> current2;
	// 	if (current1) cout << current1->c_ << endl;
	// 	if (auto apt = current->out2_.lock()) {
	// 		cout << apt->c_ << endl;
	// 	}
	// 	cout << endl;
	// }

	string::iterator it;
	vector<State> cstates;
	vector<State> nstates;
	cstates.push_back(*(states_.front()));
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








