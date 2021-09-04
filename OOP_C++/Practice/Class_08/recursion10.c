#include <stdio.h>

/*
Problem 10:

Write a recursive solution to compute lcm of two integers. 
You must not use the formula lcm(a,b) = (a x b) / gcd(a,b); find lcm from scratch...

Input:
23 488
Output:
11224

*/

int lcmRecursive(int x, int y, int lcm) {
	if (!x || !y) // lcm(x, 0) = lcm(0, y) = 0  
		return 0; // corner case

	if (lcm % x == 0 && lcm % y == 0) // x divides lcm & y divides lcm
		return lcm;
	else {
		// lcm is eiter x or 2x or 3x or 4x or .... yx
		return lcmRecursive(x, y, lcm + x);
	}
}

int main(void) {

	int x, y;
	printf("enter x and y: ");
	scanf("%d %d", &x, &y);

	printf("lcm(%d, %d) = %d\n", x, y, lcmRecursive(x, y, x));

	return 0;
}

 
// gcc -o recursion10 recursion10.c && ./recursion10