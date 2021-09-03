#include <stdio.h>
#include <math.h>

enum bool {
			FALSE = 0, 
			TRUE = 1
		  };

/*

Problem 8:

Write a recursive program to determine whether a given integer is prime or not.

Input:
49
999983
1
Output:
not prime
prime
not prime

*/

// if n is not prime, then it'll be divisible by some factor of it (which is less than or equal to sqrt(n))
enum bool isPrime(int n, int sqrt_n, int possible_factor) {
	// what will happen if we use [[ static int possible_factor = 2 ]] ?
	// ans : you can't do multiple calls from main then
	if(possible_factor <= sqrt_n) 
	{
		if(n % possible_factor == 0)
			return FALSE;
		else 
			return isPrime(n, sqrt_n, possible_factor + 1);
	}

	return (n <= 1) ? FALSE : TRUE;
}


int main(void) {

	int n;

	while(1 == scanf("%d", &n)) { // while it reads a number from the console
		if ( isPrime(n, sqrt(n + 1.0), 2) ) printf("prime\n");
		else printf("not prime\n");
	}

	return 0;
}

// note the `-lm` flag is added after the liinker command to support math.h 
// gcc -o recursion8 recursion8.c -lm && ./recursion8