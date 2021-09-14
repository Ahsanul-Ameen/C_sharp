#include <stdio.h>

int main(void) {
	int a = 1, b = 2, *p;

	p = &a; // p is assigned the address of a (p points to the location of a)

	b = *p; // is eqivalent to b = a;

	printf("value of a: %d, location of b: %p\n", *p, p);
	printf("value of b: %d, location of b: %p\n", b, &b);

	return 0;
}