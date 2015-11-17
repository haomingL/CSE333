#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <ctype.h>

#include "CharSource.h"

typedef enum {IN_WS, IN_WORD} StateType;

struct wordcounter_st {
  CharSource reader;
  StateType state;
  uint64_t  chars;
  uint64_t  words;
  uint64_t  lines;
};

#include "WordCounter.h"

WordCounter WordCounter_new(CharSource reader) {
  WordCounter this = (WordCounter)malloc(sizeof(*this));
  if ( this == NULL ) return NULL;
  return WordCounter_constructor(this, reader);
}

WordCounter WordCounter_constructor(WordCounter this, CharSource reader) {
  this->reader = reader;
  this->state = IN_WS;
  this->chars = this->words = this->lines = 0;
  return this;
}

void WordCounter_delete(WordCounter this) {
  WordCounter_destructor(this);
  free(this);
}

void WordCounter_destructor(WordCounter this) {
  // nothing to do for this class
}

uint64_t WordCounter_chars(WordCounter this) {
  return this->chars;
}

uint64_t WordCounter_words(WordCounter this) {
  return this->words;
}

uint64_t WordCounter_lines(WordCounter this) {
  return this->lines;
}

int WordCounter_count(WordCounter this) {
  char c;
  while ( (c=this->reader->vtable->nextChar(this->reader)) != EOF ) {
    this->chars++;
    if ( c == '\n' ) this->lines++;
    switch (this->state) {
      case IN_WS:  if ( !isspace(c) ) {
		     this->words++;
		     this->state = IN_WORD;
		   }
                   break;
      case IN_WORD:  if ( isspace(c) ) {
	               this->state = IN_WS;
                     }
                     break;
    }
  }
  return 1;
}
