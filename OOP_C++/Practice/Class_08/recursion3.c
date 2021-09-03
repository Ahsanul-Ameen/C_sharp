#include <stdio.h>

/*

Problem 3:

Write a recursive program to remove all odd integers from an array. 
You must not use any extra array or print anything in the function.
Just read input, call the recursive function, then print the array in main().

Input:
6
1 54 88 6 55 7
Output:
54 88 6
*/

// returns the new array size
int removeOdds(int ara[], int length) {
	static int valid_position = 0; // starts from 0
	static int scanner_position = 0; // scan the whole array

	if(scanner_position < length) {
		if(ara[scanner_position] % 2 == 0) {
			// keep the even item
			ara[valid_position] = ara[scanner_position];
			++valid_position;
		}
		++scanner_position;

		removeOdds(ara, length);
	}
	return valid_position; 
}


int main(void) {

	int n;
	scanf("%d", &n);

	int ara[n];
	for(int i = 0; i < n; i++) 
		scanf("%d", &ara[i]);

	int new_length = removeOdds(ara, n);

	//printf("%d\n", new_length);
	for(int i = 0; i < new_length; ++i) {
		printf("%d ", ara[i]);
	}
	printf("\n");

	return 0;
}

// gcc -o recursion3 recursion3.c && ./recursion3