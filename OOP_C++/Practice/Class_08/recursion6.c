#include <stdio.h>

/*

Problem 6:

Write a recursive program to compute n!

Input:
5
Output:
120

*/

long long factorial(long long n) {
	if(n <= 1) return 1; // 0! = 1! = 1

	return n * factorial(n - 1);
}


int main(void) {

	int n;
	scanf("%d", &n);

	printf("%lld\n", factorial(n)); // observe %lld here for long long datatype

	return 0;
}

// gcc -o recursion6 recursion6.c && ./recursion6