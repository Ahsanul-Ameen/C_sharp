#include <stdio.h>

/*

Problem 4:

Write a recursive solution to print the polynomial series for any input n:
1 + x + x2 + ................. + xn-1

Input:
5
Output:
1 + x + x^2 + x^3 + x^4

*/

void printPolynomial(int n, int p) { 
	if(p < n) {
		if (!p) printf("1");
		else if (p == 1) printf(" + x");
		else printf(" + x^%d", p);

		printPolynomial(n, p + 1);
	}

	if (p == n) printf("\n");
}


int main(void) {

	int n;
	scanf("%d", &n);

	printPolynomial(n, 0);

	return 0;
}

// gcc -o recursion4 recursion4.c && ./recursion4