#ifndef TRIAD_H
#define TRIAD_H

// Your typedef for Triad goes here
typedef struct { int first, second, third; } Triad;

// Your declarations of "public methods"
// for Triad go here
int triad_equal(Triad t1, Triad t2);

Triad triad_sort(Triad t);

#endif // TRIAD_H
