#include <stdio.h>

/*
Problem 11:

Suppose you are given an array of integers in an arbitrary order. Write a recursive solution to find the maximum element from the array.

Input:
5
7 4 9 6 2
Output:
9

*/

int findMax(int ara[], int n, int current_max) {
	if (n > 0) {
		if (ara[n - 1] > current_max) {
			current_max = ara[n - 1];
		}
		return findMax(ara, n - 1, current_max);

	}

	return current_max;
}

int main(void) {

	int ara[] = {7, 4, 9, 6, 2};
	int n = sizeof(ara) / sizeof(ara[0]);

	printf("max element : %d\n", findMax(ara, n, -1));

	return 0;
}

 
// gcc -o recursion11 recursion11.c && ./recursion11