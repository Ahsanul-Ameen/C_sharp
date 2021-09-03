#include <stdio.h>

/*

Problem 7:

Write a recursive program to compute nth fibonacci number. 1st and 2nd fibonacci numbers are 1, 1.

Input:
6
Output:
8

*/


// 1 1 2 3 5 8 13 21 ... 

int fib(int n) {
	if(n <= 2) return 1; 

	return fib(n - 1) + fib(n - 2);
}


int main(void) {

	int n;
	scanf("%d", &n);

	printf("%d\n", fib(n));

	return 0;
}

// gcc -o recursion7 recursion7.c && ./recursion7