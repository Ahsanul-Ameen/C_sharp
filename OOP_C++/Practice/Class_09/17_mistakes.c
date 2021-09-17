#include <stdio.h>



int main(void) {


	int i, *ip;

	i = 10;
	ip = &i;

	printf("%d\n", *ip);
	printf("%lu\n", sizeof(int *));


	double a = 14.667, b;
	
	double *dp = &a;
	printf("%lu\n", sizeof(dp));

	/*ip = dp; // do not do this
	ip = &b; // do not do this
	ip = ip * 4; // invalid*/

	b = *dp;

	printf("%lf\n", b);


	printf("%p, %p\n", dp, dp + 8);

	float c = 11.11;

	// dp = &c; // do not do this
	double cd = c;

	return 0;
}