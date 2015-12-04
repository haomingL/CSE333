#include <iostream>
#include <iomanip>

#include "Tokenizer.h"
#include "TokenCounter.h"

using namespace std;

int main(int argc, char *argv[]) {
  if ( argc != 2 && argc != 3 ) {
    cerr << "Usage: "
	 << argv[0]
	 << " filename [separator character string]"
	 << endl;
    return 1;
  }

  string sep(" \t\n");  // default separator is whitespace
  if ( argv[2] ) sep = argv[2];

  // Get a vector of tokens in the file
  Tokenizer tokenizer(argv[1], sep);
  auto tokens = tokenizer.getTokens();

  // Count the number of instances of each token and then get the top N
  TokenCounter tokenCounter(tokens);
  auto top = tokenCounter.getTop(10);

  // Print out the top N
  for ( auto const &el : top ) {
    cout << setw(8) << el.second << "   " << el.first << endl;
  }

  return 0;
}
