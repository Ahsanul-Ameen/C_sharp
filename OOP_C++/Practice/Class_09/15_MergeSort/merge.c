/**
 * Merge a[] of size m and b[] of size n into c[] of size (m + n). 
 * 
 * Mergesort: Use merge() to sort an integer array of size n
**/

#include "mergesort.h"

void merge(int a[], int b[], int c[], int m, int n)
{
	int i = 0, j = 0, k = 0;

	while (i < m && j < n) 
		c[k++] = (a[i] < b[j]) ? a[i++] : b[j++];

	while (i < m) 		/* Pick up any remainder */
		c[k++] = a[i++];
	while (j < n)
		c[k++] = b[j++];
}

void mergesort(int key[], int n) 
{
	int j, k, p, *w;

	// for (p = 1; p < n; p <<= 1) 	/* p's last value should be gt or eq to n */
	// 	;
	// if (n < m) {
	// 	printf("ERROR: Array size not a power of 2 - bye!\n");
	// 	exit(1)
	// }

	w = calloc(n, sizeof(int));		/* allocate workspace */
	assert(w != NULL); 				/* check that calloc() worked */

	// log2(n) pass total : pair, quartet, octet, ... so on
	for (k = 1; k < n; k <<= 1) { 
		for (j = 0; j + k <= n ; j += (k << 1)) {
			/**
			 *  Merge two subarrays of key[] into a subarray of w[]
			 *  first half is of size k, second half is either k or less than it
			 *  this case happens only if n is not a power of tow
			**/
			p = (k < n - j - k)? k : n - j - k; 
			merge(key + j, key + j + k, w + j, k, p);
			
			// printf("[%d %d] + [%d %d]\n", j, j + k - 1, j + k, j + k + p - 1);
		}
		wrt(w, n, k << 1);		/* Print interim table with proper gap */

		for (j = 0; j < n; ++j)	
			key[j] = w[j];		  	/* Write w back into key */
	}

	free(w);						/* free the workspace */
}