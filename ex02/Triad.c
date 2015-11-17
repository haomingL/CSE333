#include "Triad.h"

void swap(int* a, int* b);

int triad_equal(Triad t1, Triad t2) {
	return (t1.first == t2.first) &&
		   (t1.second == t2.second) &&
		   (t1.third == t2.third);
}

Triad triad_sort(Triad t) {
	if (t.second < t.first)
		swap(&t.first, &t.second);

	if (t.third < t.second)
		swap(&t.second, &t.third);

	if (t.second < t.first)
		swap(&t.first, &t.second);

	return t;
}

void swap(int* a, int* b) {
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}