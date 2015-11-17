// Haoming Liu
// 1332998
// haoming@cs.washington.edu

#ifndef WORDCOUNTER_H
#define WORDCOUNTER_H

#include <string>
#include "FileReader.h"

typedef enum {IN_WS, IN_WORD} StateType;

class WordCounter {
 private:
  StateType state_;
  uint64_t  chars_;
  uint64_t  words_;
  uint64_t  lines_;

  int count(FileReader& reader);

 public:
  WordCounter(FileReader& reader);
  uint64_t getChars();
  uint64_t getWords();
  uint64_t getLines();
  ~WordCounter();
};

#endif // WORDCOUNTER_H
