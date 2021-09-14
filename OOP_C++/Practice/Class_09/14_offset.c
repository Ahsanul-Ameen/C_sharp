#include <stdio.h>
#include <stdlib.h>



int main(void) {

	int n;
	double *a;

	/**
	 * suppose for mathematical reason, we need to access a[1], a[2], ... , a[n]
	 * 
	 * we can do 
	 * 	a = calloc(n + 1, sizeof(double));
	 * 
	 * as the size is one more than n, we can disregard a[0] and continue on 
	 * */

	n = 10;

	a = calloc(n + 1, sizeof(double));

	a[1] = a[n] = 4;
	printf("%lf %lf\n", *(a + 1), *(a + n));

	free(a);


	/**
	 * An alternative scheme can be applied. 
	 * 
	 * First write,
	 * 	a = calloc(n, sizeof(double));
	 * 
	 * At this point we have in memory..
	 * 
	 * 	[ 0 | 1 | 2 | .... | n - 1 ]
	 * 
	 *    ^
	 *    a 
	 * 
	 * Now write,
	 * 	--a  // offset the pointer
	 * 
	 * The picture of the memory has been changed relatively with the modification of base address 
	 * 
	 *  [ 0 | 1 | 2 | .... | n ]
	 *       +----------------+    // '+-...-+' represents actuall allocated memory blocks	
	 *    ^
	 *    a 
	 * 
	 * Note that (a + 0) is not owned by the programmer, so a[0] should not be accessed.
	 * 
	 * The elements a[1], a[2], ... , a[n] (previously a[0], ... , a[n-1]) 
	 * are now accessible to the programmer.
	 * 
	 * To deallocate the space, we can write, 
	 * 
	 * 	 free(a + 1);  // free up the contiguous allocated block  
	 * */


	a = malloc(n * sizeof(double));		// allocate memory for n items
	--a;								// pull back the base pointer
	a[1] = a[n] = 33;					// use previous a[0] as a[1] and previous a[n-1] as a[n] 

	printf("%lf %lf\n", *(a + 1), a[n]);

	free(a + 1);						// free up space 

	a = 0;								// 'a' should now point to NULL value, 
										// not any other valid address in the memory

	return 0;
}