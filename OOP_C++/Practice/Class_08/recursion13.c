#include <stdio.h>

/*
Problem 13:

Implement linear search recursively, i.e. given an array of integers, find a specific value from it.
Input format: first n, the number of elements. Then n integers. Then, q, number of query, then q integers. 
Output format: for each of the q integers, print its index (within 0 to n-1) in the array or print 'not found',
whichever is appropriate.

Input:
5
2 9 4 7 6
2
5 9
Output:
not found
1

*/

int linearSearchRec(const int *ara, const int n, const int v, int current_indx) {
	if (current_indx == n)
		return -1;	// not found
	
	if (ara[current_indx] == v)
		return current_indx;	// found at current_index
	else 
		return linearSearchRec(ara, n, v, current_indx + 1); // search the next part of the array
}

int main(void) {

	int n;
	scanf("%d", &n);
	int ara[n];
	for(int i = 0; i < n; i++) scanf("%d", (ara + i)); // or &ara[i] also suffices

	int q;
	scanf("%d", &q);
	for(int i = 0, v; i < q; ++i) {
		scanf("%d", &v);
		// find if v belongs to the array
		v = linearSearchRec(ara, n, v, 0);
		if(v != -1) 
			printf("%d\n", v);
		else 
			printf("not found\n");
	}

	return 0;
}

 
// gcc -o recursion13 recursion13.c && ./recursion13