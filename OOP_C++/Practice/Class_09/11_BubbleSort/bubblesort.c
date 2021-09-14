
#include <stdio.h>

void swap(int *, int *);

void printArray(int a[], int n);

void bubble(int a[], int n) { /* n is the size of a[] */
	int i, j;

	for (i = 0; i < n - 1; ++i) { // at least this many pass need in worst case {4, 3, 2, 1}
		for (j = n - 1; j > i; --j) 
			if (a[j - 1] > a[j])
				swap(&a[j - 1], a + j);
		
		{
			printf("Pass %d:\t", i);
			printArray(a, n);
		}
	}
}


int main(void) {

	int a[] = {7, 3, 66, 3, -5, 22, -77, 2};
	{
		printf("Unordered data:\t");
		printArray(a, 8);
	}	
	bubble(a, 8);

	return 0;
}



void swap(int *x, int *y) {
	*x += *y, *y = *x - *y, *x = *x - *y;
}


void printArray(int a[], int n) {
	for(int i = 0; i < n; ++i) 
		printf("%d  ", a[i]);
	printf("\n");
}


/**
 * simulation:
 *  Array:
 * {4, 3, 2, 1} 
 *  i = 0:
 * {1| 4, 3, 2}
 *  i = 1:
 * {1, 2| 4, 3}
 *  i = 2:
 * {1, 2, 3| 4} -> {1, 2, 3, 4}
 * */