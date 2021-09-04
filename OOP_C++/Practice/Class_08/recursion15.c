#include <stdio.h>

/*
Problem 15:

Write a recursive solution to get the reverse of a given integer. Function must return an int

Input:
123405
Output:
504321

*/

int reverse(int n, int r) {

	if (!n) 
		return r;
	
	// r *= 10; // left shift r one digit
	// r += n % 10; // grab the last digit and append it to r

	reverse(n / 10, r * 10 + n % 10);
}

int main(void) {

	int n;
	scanf("%d", &n);
	printf("%d\n", reverse(n, 0));

	return 0;
}

 
// gcc -o recursion15 recursion15.c && ./recursion15