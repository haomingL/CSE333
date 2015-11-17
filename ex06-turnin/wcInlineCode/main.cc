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

#include <iostream>
#include <cstdint>

#include "FileReader.h"
#include "WordCounter.h"

using namespace std;

void usage(const char* exeName) {
  cerr << "Usage: " << exeName 
       << " file" << endl
       << "Prints out the number of lines, words, and characters in the file" << endl;
  exit(1);
}

int main(int argc, char* argv[]) {
  if ( argc != 2 ) usage(argv[0]);

  FileReader reader(argv[1]);
  WordCounter counter(reader);

  cout << counter.getLines() << " lines, " 
       << counter.getWords() << " words, "
       << counter.getChars() << " characters"
       << endl;
}
