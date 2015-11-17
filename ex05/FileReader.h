#ifndef FILEREADER_H
#define FILEREADER_H

// "subclasses" CharSource
#include "CharSource.h"  // not strictly needed for this particular example

#include <stdio.h>
#include <sys/types.h>

typedef struct FileReader_st *FileReader;

typedef struct FileReader_vtable_st {
  char (*nextChar)(FileReader this);
  void (*delete)(FileReader this);
} FileReader_vtable;

typedef struct FileReader_st  * FileReader;

FileReader FileReader_new(const char *filename);
FileReader FileReader_constructor(FileReader this, const char *filename);

void FileReader_destructor(FileReader this);

#endif // FILEREADER_H
