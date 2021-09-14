#include <stdio.h>

/**
 * The effect of "call-by-reference" is accomplished by
 * 
 * 1. Declaring a function parameter to be a pointer
 * 2. Using the dereferenced pointer in the function body
 * 3. Passing an address as an argument when the function is called
 * 
 * */


// function paramets are pointer
// int *p = &i, *q = &j	
// something like this happens during function call
void swap(int *p, int *q) { // well, well change the contents at original locations
	int tmp;

	tmp = *p;

	*p = *q;

	*q = tmp;
}


// function paramets are simple integers
// int p = j, q = i	
// something like this happens during function call
void zawp(int p, int q) { // function local scope begins
	int tmp;

	tmp = p;

	p = q;

	q = tmp;
}


int main(void) {
	int i = 3, j = 5;

	// call by reference
	swap(&i, &j);
	printf("%d %d\n", i, j); // 5 3 is printed

	// call by value
	zawp(j, i); // no change
	printf("%d %d\n", j, i); // 3 5 is printed

	return 0;
}