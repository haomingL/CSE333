#ifndef CHARSOURCE_H
#define CHARSOURCE_H

// This is, logically, a protected base class:  no user
// code should ever try to create one of these objects
// (no directly #include this file)

typedef struct CharSource_st *CharSource;

typedef struct CharSource_vtable_st {
  char (*nextChar)(CharSource this);
  void (*delete)(CharSource this);
} CharSource_vtable;

typedef struct CharSource_st {
  CharSource_vtable *vtable;
} * CharSource;


// No one can 'new' a _CharSource
CharSource CharSource_constructor(CharSource this);

// There's nothing to do on deletion

#endif // CHARSOURCE_H
