// Haoming Liu
// 1332998
// haoming@cs.washington.edu

#ifndef WORDCOUNTER_H
#define WORDCOUNTER_H

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <ctype.h>
#include "FileReader.h"

typedef enum {IN_WS, IN_WORD} StateType;

class WordCounter {
 private:
  StateType state_;
  uint64_t  chars_;
  uint64_t  words_;
  uint64_t  lines_;

  int count(FileReader& reader) {
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

 public:
  WordCounter(FileReader& reader) {
    state_ = IN_WS;
    chars_ = words_ = lines_ = 0;
    count(reader);
  }
  
  uint64_t getChars() {
    return chars_;
  }

  uint64_t getWords(){
    return words_;
  }

  uint64_t getLines(){
    return lines_;
  }

  ~WordCounter() { /* Do nothing? */ }
};

#endif // WORDCOUNTER_H
