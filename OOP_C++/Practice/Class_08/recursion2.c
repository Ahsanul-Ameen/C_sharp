#include <stdio.h>

/*

Problem 2:

Write a recursive function to print an array in the following order.
[0] [n-1]
[1] [n-2]
.........
.........
[(n-1)/2] [n/2]

Input:
5
1 5 7 8 9
Output:
1 9
5 8
7 7
*/

void printTwoSide(int ara[], int left_indx, int right_indx) {
	if (left_indx <= right_indx) {
		printf("%d %d\n", ara[left_indx], ara[right_indx]);

		printTwoSide(ara, left_indx + 1, right_indx - 1);
	}
}


int main(void) {

	int n;
	scanf("%d", &n);

	int ara[n];
	for(int i = 0; i < n; i++) 
		scanf("%d", &ara[i]);

	printTwoSide(ara, 0, n - 1);

	return 0;
}

// gcc -o recursion2 recursion2.c && ./recursion2