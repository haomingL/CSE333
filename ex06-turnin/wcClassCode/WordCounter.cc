// Haoming Liu
// 1332998
// haoming@cs.washington.edu

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <ctype.h>

#include "WordCounter.h"

WordCounter::WordCounter(FileReader& reader) {
  state_ = IN_WS;
  chars_ = words_ = lines_ = 0;
  count(reader);
}

uint64_t WordCounter::getChars() {
  return chars_;
}

uint64_t WordCounter::getWords() {
  return words_;
}

uint64_t WordCounter::getLines() {
  return lines_;
}

int WordCounter::count(FileReader& reader) {
  char c;
  while ((c=reader.nextChar()) != EOF ) {
    chars_++;
    if ( c == '\n' ) lines_++;
    switch (state_) {
      case IN_WS:  if ( !isspace(c) ) {
		     words_++;
		     state_ = IN_WORD;
		   }
                   break;
      case IN_WORD:  if ( isspace(c) ) {
	               state_ = IN_WS;
                     }
                     break;
    }
  }
  return 1;
}

WordCounter::~WordCounter() {
  // do something?
}
