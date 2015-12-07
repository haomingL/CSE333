#include "State.h"

State::State(int c) : c_(c) { }

State::~State() {

}

void State::patch1(shared_ptr<State> ptr) {
	out1_ = ptr;
}

void State::patch2(weak_ptr<State> ptr) {
	out2_ = ptr;
}

bool State::match(int c) {
	return c == c_;
}