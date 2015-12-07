// Haoming Liu
// 1332998
// haoming@uw.edu

#include <iostream>
#include <fstream>

#include "SentenceMatcher.h"

using namespace std;

int main(int argc, char** argv) {
	if ( argc != 2 && argc != 3 ) {
	    cerr << "Usage: "
		 << argv[0]
		 << " [regular expression] [filename]"
		 << endl;
	    return EXIT_FAILURE;
	}

	string regex(argv[1]);
	SentenceMatcher sm(regex);

	string filename(argv[2]);
	ifstream file(filename);
	string line;
	while (getline(file, line)) {
		cout << line << endl;
	}
	return EXIT_SUCCESS;
}