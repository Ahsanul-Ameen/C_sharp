#include <stdio.h>

/*Problem 1:

You will be given an array of integers, write a recursive solution to print it in reverse order.

Input:
5
69 87 45 21 47
Output:
47 21 45 87 69*/

void printReversedArray(int ara[], int length) {
	if(length <= 0) {
		printf("\n");
		return;
	}

	printf("%d ", ara[length - 1]);
	
	printReversedArray(ara, length - 1);
}


int main(void) {

	int n;
	scanf("%d", &n);

	int ara[n];
	for(int i = 0; i < n; i++) 
		scanf("%d", &ara[i]);

	printReversedArray(ara, n);

	return 0;
}

// gcc -o recursion1 recursion1.c && ./recursion1