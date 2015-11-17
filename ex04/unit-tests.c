/*
 * Copyright 2013 John Zahorjan
 *
 *  This file is part of the UW CSE 333 course exercises (333exer).
 *
 *  333exer is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  333exer is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with 333exer.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>    // for EXIT_SUCCESS, malloc, free

#include "../ctest/ctest.h"

#include "Stack.h"

CTEST(stack, new_delete) {
  Stack s = stack_new();
  ASSERT_NOT_NULL(s);
  stack_delete(s);
  // just make sure we get here
  ASSERT_NULL(NULL);
}

CTEST(stack, empty_pop) {
  Stack s = stack_new();
  StackElement el = stack_pop(s);
  ASSERT_EQUAL((long)el, 0);  // This says what to return in this situation
  stack_delete(s);
}


static void _pushPopArray(StackElement val[], unsigned int nElements) {
  int i;
  Stack s = stack_new();
  for (i=0; i<nElements; i++) {
    stack_push(s, val[i]);
  }
  for (i=nElements-1; i>=0; i--) {
    StackElement el = stack_pop(s);
    ASSERT_EQUAL((long)val[i], (long)el);
  }
  stack_delete(s);
}

CTEST(stack, push_pop_small_long) {
  StackElement val[] = {(StackElement)2, 
                        (StackElement)4, 
                        (StackElement)8,
                        (StackElement)16,
                        (StackElement)32,
                        (StackElement)64
                       };
  _pushPopArray(val, sizeof(val)/sizeof(StackElement));
}

CTEST(stack, push_pop_large_long) {
  const int SIZE = 10000;
  unsigned long int i;
  StackElement *val = (StackElement*)malloc(SIZE * sizeof(StackElement));
  for (i=0; i<SIZE; i++) {
    val[i] = (StackElement)i;
  }
  _pushPopArray(val, SIZE);
  free(val);
}

CTEST(stack, push_pop_large_ptr) {
  const int SIZE = 10000;
  long int i;
  StackElement *val = (StackElement*)malloc(SIZE * sizeof(StackElement));
  for (i=0; i<SIZE; i++) {
    val[i] = (StackElement)malloc(sizeof(double));
    if (val[i] == NULL) break;
  }
  _pushPopArray(val, i);
  for (i=i-1; i>=0; i--) {
    free(val[i]);
  }
  free(val);
}

CTEST(stack, delete_delete) {
  Stack s = stack_new();
  stack_delete(s);
  stack_delete(s);
  ASSERT_NULL(NULL);  // prints a message
}


