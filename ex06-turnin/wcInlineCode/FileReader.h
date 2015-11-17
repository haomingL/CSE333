#ifndef FILEREADER_H
#define FILEREADER_H

#define  _POSIX_C_SOURCE  200809L

#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <string>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

class FileReader {
 private:
  int   f;
  const std::string  filename;
  static const int   BUFLEN = 4096;
  char               buf[BUFLEN];
  ssize_t            bufLen;
  int                bufIndex;

  void _fileError() {
    perror(filename.c_str());
    cerr << "Some error reading file '" << filename << "'" << endl;
    exit(2);
  }

 public:
  FileReader(const std::string fname) : filename(fname) {
    f = open(filename.c_str(), O_RDONLY);
    if ( f < 0 ) _fileError();
    bufLen = 0;
    bufIndex = 0;
  }

  ~FileReader() {
    if ( 0 != close(f) ) {
      perror("fclose");
      exit(3);
    }
  }

  char nextChar() {
    if ( bufIndex >= bufLen ) {
      bufLen = read( f, buf, BUFLEN );
    if ( bufLen == -1 ) _fileError();
    if ( bufLen == 0 ) return EOF;
      bufIndex = 0;
    }
    return buf[bufIndex++];
  }
};

#endif // FILEREADER_H
