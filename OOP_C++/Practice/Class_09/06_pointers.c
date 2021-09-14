#include <stdio.h>


int main(void) {

	int 	*ip;
	float 	*fp;
	void 	*vp;

	// Legal Assignments

	ip = 0; // points to NULL

	ip = (int *) 1; // absolute memory address

	ip = vp = fp; // auto casting via void pointer

	vp = (int *) 1;

	ip = (int *)fp; // explicit type casting


	// Illegal Assignments

	/*ip = 1; // assignment to ‘int *’ from ‘int’

	vp = 1; // assignment to ‘void *’ from ‘int’

	ip = fp; // assignment to ‘int *’ from incompatible pointer type ‘float **/


	// Constructs not to be pointed at

	/*&3; // Do not point at constants : illegal

	int k = 0;
	&(k + 99); // Do not point at ordinary expressions : illegal

	register v;
	&v;	// Do not point at register variables : illegal*/


	// address operator can be applied to variables and array elements

	int a[50] = {0};
	a[0] = 2;
	a[1] = 55;
	a[33] = 47;
	a[40] = 43;

	ip = &a[0]; // equivalent to   ip = a;

	printf("a[0] = %d, a[1] = %d\n", *ip, *(ip + 1));

	int i = 10, j = 20;
	ip = &a[i + j + 3];	

	printf("a[33] = %d, a[40] = %d\n", *ip, *(ip + 7));

	ip[9] = -42; // ip aleardy points to a[33], so ip[9] or *(ip + 9) is same as a[42];
	printf("a[42] contains %d\n", a[42]);

	*(&a[25] - 5) = 200;
	printf("a[20] contains %d\n", *(a + 20));

	ip = (&a[0] + 20);

	int * np = a + 20;

	printf("a + 20 == (&*a + 20)\t------>\t%d\n", a + 20 == (&*a + 20));

	printf("((a + 10) + 10) == (&*(a + 220) - 200)\t------>\t%d\n", ((a + 10) + 10) == (&a[220] - 200));



	return 0;
}