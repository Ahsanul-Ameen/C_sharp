#include <stdio.h>


int main() {


	int *p; // declares p to be of type pointer to int

	p = 0;
	p = NULL;	// equivalent to  p = 0

	int i = 29;
	p = &i;

	printf("%d is in memory address: %p\n", i, p);
	printf("%p = %llx is the address which contains value %d\n", p, (unsigned long long)&i, *p);

	p = (int *)1776; // an absolute address in memory
	//*p = 100; // might cause segmentation fault (can't write value to certain special memory segments)


	return 0;
}