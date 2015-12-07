#ifndef STATE_H
#define STATE_H

#include <memory>

using namespace std;

class State {
	private:
		int c_;

	public:
		State(int c);
		~State();

		shared_ptr<State> out1_;
		weak_ptr<State> out2_;
		void patch1(shared_ptr<State> ptr);
		void patch2(weak_ptr<State> ptr);
		bool match(int c);
};

#endif // STATE_H