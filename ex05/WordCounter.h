#ifndef WORDCOUNTER_H
#define WORDCOUNTER_H

#include <inttypes.h>

#include "CharSource.h"

typedef struct wordcounter_st * WordCounter;

// user code calls new() (only) and it calls constructor
WordCounter WordCounter_new(CharSource reader);
WordCounter WordCounter_constructor(WordCounter this, CharSource reader);

// returns 0 for failure, >0 for success
int WordCounter_count(WordCounter this);

// user code calls delete only (and it calls destructor)
void WordCounter_delete(WordCounter this);
void WordCounter_destructor(WordCounter this);

// accessors
uint64_t WordCounter_chars(WordCounter this);
uint64_t WordCounter_words(WordCounter this);
uint64_t WordCounter_lines(WordCounter this);

#endif // WORDCOUNTER_H
