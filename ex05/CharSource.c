#include <stdio.h>
#include <stdlib.h>

#include "CharSource.h"

// default implementation of nextChar()
static char _nextChar(CharSource this) {
  return EOF;
}

static void _delete(CharSource this) {
  // (In theory, we should call the destructor,
  //  but we have no destructor.)
  free(this);
}

CharSource_vtable CHARSOURCE_CLASS_VTABLE = 
  { .nextChar = _nextChar,
    .delete = _delete 
  };

CharSource CharSource_constructor(CharSource this) {
  this->vtable = &CHARSOURCE_CLASS_VTABLE;
  return this;
}
