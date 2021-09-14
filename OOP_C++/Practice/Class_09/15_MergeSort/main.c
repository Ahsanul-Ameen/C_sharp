/** 
 * Test merge() and mergesort() 
 * 
 * https://www.hackerrank.com/contests/hw1/challenges/merge-sort/submissions/code/1336471140
 * https://leetcode.com/submissions/detail/552776029/
 * 
 * **/

#include "mergesort.h"

int main(void) 
{
	int sz, key[] = { 4, 3, 1, 67, 55, 8, 0, 4,
					 -5, 37, 7, 4, 2, 9, 1, -1, 2, 4, 99, -22, -44 };

	sz = sizeof(key) / sizeof(int); 		/* the size of key[] */

	printf("Total items: %d\n", sz);				 
	printf("Before mergesort:\n");
	wrt(key, sz, -1);

	mergesort(key, sz);

	printf("After mergesort:\n");
	wrt(key, sz, -1);

	return 0;
}