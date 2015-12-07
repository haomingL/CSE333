#include "State.h"

State::State(int c) : c_(c) { }

State::~State() {

}

bool State::match(int c) {
	return c == c_;
}
