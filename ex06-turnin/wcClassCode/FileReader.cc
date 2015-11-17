#define  _POSIX_C_SOURCE  200809L

#include <iostream>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "FileReader.h"

using namespace std;

void FileReader::_fileError() {
  perror(filename.c_str());
  cerr << "Some error reading file '" << filename << "'" << endl;
  exit(2);
}

FileReader::FileReader(const std::string fname) : filename(fname) {
  f = open(filename.c_str(), O_RDONLY);
  if ( f < 0 ) _fileError();
  bufLen = 0;
  bufIndex = 0;
}

char FileReader::nextChar() {
 if ( bufIndex >= bufLen ) {
    bufLen = read( f, buf, BUFLEN );
    if ( bufLen == -1 ) _fileError();
    if ( bufLen == 0 ) return EOF;
    bufIndex = 0;
  }
  return buf[bufIndex++];
  
}

FileReader::~FileReader() {
  if ( 0 != close(f) ) {
    perror("fclose");
    exit(3);
  }
}
