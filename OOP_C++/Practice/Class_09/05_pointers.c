#include <stdio.h>

int main(void) {

	int i = 3, j = 5, *p = &i, *q = &j, *r;

	double x;


	printf( " p == & i ---->  %d \n", p == &i ); // 1

	printf( " **&p ----> %d \n", *(*(&p)) ); // 3

	// r = &x; // r = (&x) /* illegal (incompatible pointer type) */

	printf( " 7 * *p / *q + 7 ----> %d \n", ((7 * (*p)) / (*q)) + 7 ); // (3 * 7) / 5 + 7 = 4 + 7 = 11

	// printf( " 7 * *p / *q + 7 ----> %d \n", 7 * *p / *q + 7 );
	// printf( " 7 * *p / *q + 7 ----> %d \n", 7 * *p /* q + 7 ); /* trouble? compiler treats /* as the starts of a comment */ 

	printf( " * (r = & j) *= *p ----> %d \n", (* (r = (& j))) *= (*p) ); // 5 *= 3 -> 15

	return 0;
}