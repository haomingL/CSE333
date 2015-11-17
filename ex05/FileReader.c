#define  _POSIX_C_SOURCE  200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "FileReader.h"

#define BUFLEN 4096

// Make concrete the struct FileReader_st type
struct FileReader_st {
  FileReader_vtable *vtable;
  char*   filename;
  char*   buf;
  ssize_t bufLen;
  int     bufIndex;
  int     f;
};

static void FileReader__fileError(FileReader this) {
  perror(this->filename);
  fprintf(stderr, "Some error reading file '%s'\n", this->filename);
  exit(2);
}

static char FileReader__newBuf(FileReader this) {
  if ( this->f < 0 ) FileReader__fileError(this);

  this->bufLen = read( this->f, this->buf, BUFLEN );
  if ( this->bufLen == -1 ) FileReader__fileError(this);
  if ( this->bufLen == 0 ) return EOF;
  this->bufIndex = 0;

  return this->buf[this->bufIndex++];
}

static char _nextChar(FileReader this) {
  return this->bufIndex < this->bufLen ? 
            this->buf[this->bufIndex++] : 
            FileReader__newBuf(this);
}

static void _delete(FileReader this) {
  FileReader_destructor(this);
  free(this);
}

FileReader_vtable FILEREADER_CLASS_VTABLE = 
  { .nextChar = _nextChar,
    .delete = _delete
  };

FileReader FileReader_constructor(FileReader this, const char* fname) {
  this->f = open(fname, O_RDONLY);
  if ( this->f < 0 ) FileReader__fileError(this);
  this->filename = strdup(fname);

  this->buf = (char*)malloc(BUFLEN*sizeof(char));
  if ( this->buf == NULL ) FileReader__fileError(this);

  this->bufLen = 0;
  this->bufIndex = 0;

  return this;
}

FileReader FileReader_new(const char* fname) {
  FileReader this = (FileReader)malloc(sizeof(struct FileReader_st));
  if ( this == NULL ) FileReader__fileError(this);
  this->vtable = &FILEREADER_CLASS_VTABLE;
  return FileReader_constructor(this, fname);
}

void FileReader_destructor(FileReader this) {
  if ( 0 != close(this->f) ) FileReader__fileError(this);
  if ( this->filename ) free(this->filename);
  if ( this->buf ) free(this->buf);
}

