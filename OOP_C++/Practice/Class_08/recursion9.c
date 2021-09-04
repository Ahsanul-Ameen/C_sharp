#include <stdio.h>

/*

Problem 9:

Write a recursive function that finds the gcd of two non-negative integers.

Input:
25 8895
Output:
5

*/

int gcdRecursive(int x, int y) {
	return !y ? x : gcdRecursive(y, x % y);
}

int main(void) {

	int x, y;
	printf("enter x and y: ");
	scanf("%d %d", &x, &y);

	printf("gcd(%d, %d) = %d\n", x, y, gcdRecursive(x, y));

	return 0;
}

 
// gcc -o recursion9 recursion9.c && ./recursion9