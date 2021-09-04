#include <stdio.h>

/*
Problem 14:

Implement binary search recursively, i.e. given an array of sorted integers, find a query integer from it.
Input format: first n, the number of elements. Then n integers. Then, q, number of query, then q integers. Output format: for each of the q integers, print its index (within 0 to n-1) in the array or print 'not found', whichever is appropriate.

Input:
5
1 2 3 4 5
2
3 -5
Output:
2
not found

*/

int binarySearchRec(const int *ara, int lo, int hi, int v) {
	if (lo > hi) return -1;

	int mid_indx = lo + ((hi - lo) >> 1); // right shift means divide by 2

	if (ara[mid_indx] == v)
		return mid_indx;
	else if (ara[mid_indx] < v) 
		return binarySearchRec(ara, mid_indx + 1, hi, v);
	else 
		return binarySearchRec(ara, lo, mid_indx - 1, v);
}

int main(void) {

	int n;
	scanf("%d", &n);
	int ara[n];
	for(int i = 0; i < n; i++) scanf("%d", &ara[i]); // or  (ara + i) also suffices

	int q;
	scanf("%d", &q);
	for(int i = 0, v; i < q; ++i) {
		scanf("%d", &v);
		// find if v belongs to the array
		v = binarySearchRec(ara, 0, n - 1, v);
		if(v != -1) 
			printf("%d\n", v);
		else 
			printf("not found\n");
	}

	return 0;
}

 
// gcc -o recursion14 recursion14.c && ./recursion14