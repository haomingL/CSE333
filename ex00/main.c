// Haoming Liu
// 1332998
// haoming@cs.washington.edu

#include <stdio.h>

//---------------------------------------
// Returns exit code meaning TRUE
//---------------------------------------

int main(int argc, char *argv[]) {
  if (*(argv[0] + 2) == 't')
  	return 0;
  else if (*(argv[0] + 2) == 'f')
  	return 1;
}