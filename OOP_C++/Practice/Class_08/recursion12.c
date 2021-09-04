#include <stdio.h>

/*
Problem 12:

Write a recursive solution to find the second maximum number from a given set of integers.

Input:
5
5 8 7 9 3
Output:
8

*/

int findSecondMax(int ara[], const int n, int first_max, int second_max) {
	if (n > 0) {
		if (ara[n - 1] > first_max) {
			second_max = first_max;
			first_max = ara[n - 1];
		} 
		else if (ara[n - 1] > second_max) {
			second_max = ara[n - 1];
		}
		return findSecondMax(ara, n - 1, first_max, second_max);

	}

	return second_max;
}

int main(void) {

	int n;
	scanf("%d", &n);
	int ara[n];
	for(int i = 0; i < n; i++) scanf("%d", (ara + i)); // or &ara[i] also suffices

	printf("second max element : %d\n", findSecondMax(ara, n, -1, -2));

	return 0;
}

 
// gcc -o recursion12 recursion12.c && ./recursion12