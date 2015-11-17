// License

// This version has a more flexible code struture: extracting
// characters from their source is left ot a helper class,
// file_reader.
// Depending on which file_reader implementation you link with,
// you get different versions of the application.
// To build, compile this file and one of the file_reader .c files.
//
// file_reader.c:  Does fgetc
// file_reader_getline.c: Uses getline to retrieve a line at a time
// file_reader_read: Uses the unbuffered file interface, and reads file chunks

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <ctype.h>

#include "FileReader.h"
#include "WordCounter.h"

void usage(const char* exeName) {
  fprintf(stderr, "Usage: %s file\nPrints out the number of lines, words, and characters in the file\n", exeName);
  exit(1);
}

int main(int argc, char* argv[]) {
  if ( argc != 2 ) usage(argv[0]);
  FileReader reader = FileReader_new(argv[1]);
  if ( reader == NULL ) usage(argv[0]);
  
  WordCounter wc = WordCounter_new((CharSource)reader);

  WordCounter_count(wc);
  ((CharSource)reader)->vtable->delete((CharSource)reader);

  printf(" %" PRIu64 " lines, %" PRIu64 " words, %" PRIu64 " characters\n",
	 WordCounter_lines(wc),
         WordCounter_words(wc),
         WordCounter_chars(wc) );

  WordCounter_delete(wc);
}
