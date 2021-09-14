#include "mergesort.h"

// gap = -1 means no gap
void wrt(int key[], int sz, int gap) {
	int i;

	for (i = 0; i < sz; ++i) {
		printf("%4d%s", key[i], ((i < sz - 1)? "" : "\n"));
		if (gap != -1 && i < sz - 1 && (i + 1) % gap == 0)
			printf("|");
	}
}