#include <stdio.h>
#include <stdlib.h>

int *foo() {
	int variable  = 10;

	int *vp = &variable;

	*vp = 11;

	return vp;
}

void boo(int n) {

	if(n > 0) {
		printf("boo(%d)\n", n);
		boo(--n);
	}

	return;
}

void alloc(int *p) {
	*p = 111;

	p = (int *)malloc(sizeof(int));
	*p = 112;
	free(p);
	p = NULL; // p is not dangling anymore
}

int* doo() {
	int *ip = malloc(sizeof(int));
	*ip = 10;
	free(ip);
	//ip = NULL;  // do this to make ip non dangling
	return ip;
}


int main () {

	int *ip = NULL;

	ip = (int *)calloc(1, sizeof (int));

	*ip = 47;

	printf("%d\n", *ip);

	printf("pointer points to address %p containing value %d\n", ip, *ip);

	free(ip);

	//ip = 0; // make ip a null pointer

	printf("dangling pointer points to somewhere containing garbage value %d\n", *ip);

	// --------------------------



	ip = foo();

	printf("dangling pointer points to address %p containing value %d\n", ip, *ip);

	boo(2); // eat the call stack space

	printf("dangling pointer points to address %p containing value %d\n", ip, *ip);

	// ---------------------------

	ip = NULL;

	{
		int v = 20;
		ip = &v;
	}
	// v falls out of scope
	// ip is now a dangling pointer 

	printf("dangling pointer points to address %p containing value %d\n", ip, *ip);

	// ----------------------------

	ip = 0;

	ip = doo();
	printf("dangling pointer points to address %p containing value %d\n", ip, *ip);

	alloc(ip);
	printf("still dangling pointer points to address %p containing value %d\n", ip, *ip);

	
	ip = NULL;

	return 0;
}


// gcc 02_dangling_pointers.c -o 02_dangling_pointers.exe && ./02_dangling_pointers.exe