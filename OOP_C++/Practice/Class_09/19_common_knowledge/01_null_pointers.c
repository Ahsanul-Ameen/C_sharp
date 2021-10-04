#include <stdio.h>
#include <stdlib.h>


int main () {

	int *ip = NULL;

	ip = (int *)malloc(sizeof (int));

	*ip = 55;

	printf("%d\n", *ip);

	free(ip);

	ip = 0; // make ip a null pointer



	return 0;
}


// gcc 01_null_pointers.c -o 01_null_pointers.exe && ./01_null_pointers.exe