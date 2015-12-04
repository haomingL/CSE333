#include <fstream>
#include <sstream>

#include "Tokenizer.h"

using namespace std;

Tokenizer::Tokenizer(const string &filename, const string &sep) {
  ifstream infile(filename.c_str());

  if ( infile.is_open() ) {
    string line;
    while ( getline (infile,line) )
    {
      std::stringstream ss(line);
      std::string item;
      while (std::getline(ss, item)) {
	size_t startPos = 0;
	size_t endPos;
	while ((endPos = item.find_first_of(sep,startPos)) != string::npos) {
	  if ( endPos > startPos )
	    tokens.push_back(item.substr(startPos, endPos-startPos));
	  startPos = endPos + 1;
	}
      }
    }
    infile.close();
  }
}

const vector<string> & Tokenizer::getTokens() {
  return tokens;
}
