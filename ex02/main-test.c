#include <stdio.h>
#include "Triad.h"

void print_triad(Triad t) {
  printf ("{%d, %d, %d}", t.first, t.second, t.third);
}

int main(int argc, char *argv[]) {
  int i;

  // This creates an array of six Triads, initialized in the 
  // obvious way (given the syntax here)
  Triad triad_vec[6] = { {1,2,3},
			 {1,3,2},
			 {2,1,3},
			 {2,3,1},
			 {3,1,2},
			 {3,2,1}
                       };

  Triad expected_result = {1,2,3};

  // First test triad_equal
  printf("triad_equal(");
  print_triad(triad_vec[0]);
  printf(", ");
  print_triad(triad_vec[0]);
  printf(") => ");
  if ( triad_equal(triad_vec[0], triad_vec[0]) ) {
    printf("Success!\n");
  } else {
    printf("Failure!\n");
  }

  printf("!triad_equal(");
  print_triad(triad_vec[0]);
  printf(", ");
  print_triad(triad_vec[1]);
  printf(") => ");
  if ( !triad_equal(triad_vec[0], triad_vec[1]) ) {
    printf("Success!\n");
  } else {
    printf("Failure!\n");
  }


  // Now test triad_sort
  for (i=0; i<6; i++) {
    print_triad(triad_vec[i]);
    printf(" => ");
    Triad result = triad_sort(triad_vec[i]);
    if ( triad_equal(result, expected_result) ) {
      printf("Success!\n");
    }
    else {
      printf("Failure! ");
      print_triad(result);
      printf("\n");
    }
  }

  return 0;
}
