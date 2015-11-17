/*
 * Haoming Liu
 * 1332998
 * haoming@uw.edu
 *
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

#include <stdio.h>     // for printf
#include <stdlib.h>    // for EXIT_SUCCESS, malloc, free
#include <inttypes.h>  // for uint8_t, PRIx8, etc.

#include "../ctest/ctest.h"

#include "DumpHex.h"

typedef struct {
    char    charVal;
    int32_t intVal;
    float   floatVal;
    double  doubleVal;
} Ex3Struct;

// The test data given to DumpHex -- an initialized structure.
static Ex3Struct structVal = { '0', 1, 1.0, 1.0 };

CTEST(dumphex, char) {
  const char *expectedStr = "30";
  char *answerBuf = DumpHex(&structVal.charVal, sizeof(structVal.charVal));
  ASSERT_STR( expectedStr, answerBuf );
  free(answerBuf);
}

CTEST(dumphex, int) {
  const char *expectedStr = "01 00 00 00";
  char *answerBuf = DumpHex(&structVal.intVal, sizeof(structVal.intVal));
  ASSERT_STR( expectedStr, answerBuf );
  free(answerBuf);
}

CTEST(dumphex, float) {
  const char *expectedStr = "00 00 80 3f";
  char *answerBuf = DumpHex(&structVal.floatVal, sizeof(structVal.floatVal));
  ASSERT_STR( expectedStr, answerBuf );
  free(answerBuf);
}

CTEST(dumphex, double) {
  const char *expectedStr = "00 00 00 00 00 00 f0 3f";
  char *answerBuf = DumpHex(&structVal.doubleVal, sizeof(structVal.doubleVal));
  ASSERT_STR( expectedStr, answerBuf );
  free(answerBuf);
}

// YOUR UNIT TEST HERE
CTEST(dumphex, struct) {
  const char *expectedStr = "30 00 00 00 01 00 00 00 00 00 80 3f 00 00 00 00 00 00 00 00 00 00 f0 3f";
  char *answerBuf = DumpHex(&structVal, sizeof(structVal));
  ASSERT_STR( expectedStr, answerBuf );
  free(answerBuf);
}