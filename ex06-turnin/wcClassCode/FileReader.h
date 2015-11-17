#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>

class FileReader {
 private:
  int   f;
  const std::string  filename;
  static const int   BUFLEN = 4096;
  char               buf[BUFLEN];
  ssize_t            bufLen;
  int                bufIndex;

  void _fileError();

 public:
  FileReader(const std::string fname);
  ~FileReader();

  char nextChar();
};

#endif // FILEREADER_H
