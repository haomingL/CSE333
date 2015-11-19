#include <iostream>
#include <deque>

#include "Element.h"

using namespace::std;

int main(int argc, char* argv[]) {
  deque<Element> forward;
  deque<Element> reverse;

  for (int i=1; i<argc; i++) {
    Element next(argv[i]);    // invokes a normal constructor
    forward.push_back(next);  // invokes the copy constructor
    *argv[i] = '\0';          // mangle original string to make sure Element makes a copy
  }

  reverse = forward;          // does element-by-element copy

  while ( forward.size() > 1 ) {
    Element f = forward.front();  // copy constructor
    forward.pop_front();
    Element r = reverse.back();   // copy constructor
    reverse.pop_back();
    
    if ( !(f == r) ) {            // equality operator
      // toString() returns the C string the Element contains
      cout << f.toString() << " != " << r.toString() << endl;
      exit(1);
    }
  }

  cout << "Arguments are symmetric" << endl;
  return 0;
}
