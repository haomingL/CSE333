#ifndef STATE_H
#define STATE_H

#include <memory>

using namespace std;

class State {
	public:
		State(int c);
		~State();
		
		int c_;
		shared_ptr<State> out1_;
		weak_ptr<State> out2_;
		bool match(int c);
};

#endif // STATE_H