#include <stdio.h>

/*

Problem 5:

Write a recursive solution to evaluate the previous polynomial for any given x and n.
Like, when x=2 and n=5, we have 1 + x + x2 + ................. + xn-1 = 31

Input:
2 5
Output:
31

*/

int evaluatePolynomial(int x, int n) {
	static int p = 0; 
	static int power_of_x = 1; // starts from x^0
	if(p < n) {
		int current_term = power_of_x;
		p++;
		power_of_x *= x;
		//printf("%d\n", current_term);
		return current_term + evaluatePolynomial(x, n);
	}
	return 0;
}


int main(void) {

	int x, n;
	scanf("%d %d", &x, &n);

	printf("%d\n", evaluatePolynomial(x, n));

	return 0;
}

// gcc -o recursion5 recursion5.c && ./recursion5