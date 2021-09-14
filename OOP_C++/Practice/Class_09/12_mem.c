#include <stdio.h>
#include <stdlib.h>


/**
 * 
 * stdlib.h contains
 * 
 * malloc() -> memory allocation 
 * calloc() -> contiguous allocation
 * 
 * can be used to dynamically create space for arrays, structures and unions.
 * */



int main(void) {

	
	int *a;						// to be used as an array of int
	int n;						// the size of the array

	n = 10;						// get n from somewhere, perhaps interactively from user
	a = calloc(n, sizeof(int)); // get a space for a; use a as an array	

	/**
	 * calloc() takes 2 arguments both of type size_t
	 * 
	 * size_t typically is of an unsigned integral type [made equivalent by typedef in stdlib.h]
	 * 
	 * calling pattern : calloc(n, el_size);
	 * 
	 * allocates contiguous space in memory for an array of n elements, 
	 * with each element el_size bytes 
	 * 
	 * The space is initialized with all bits set to ZERO.
	 * 
	 * If the call is successful, a pointer of type void * 
	 * that points to the base of the array in memory is returned; 
	 * otherwise, NULL is returned. 
	 * 
	 * Note that the use of the si zeof operator makes code appropriate for machines 
	 * having either 2- or 4-byte words.
	 * 
	 * 
	 * */




	/**
	 * The programmer uses ma11oc() in a similar fashion. 
	 * This function takes a single argument of type size_t. 
	 * If the call is successful, it returns a pointer of type void *
	 * that points to the requested space in memory; 
	 * otherwise, NULL gets returned. 
	 * 
	 * some calloc call:
	 * 	a = calloc(n, sizeof(int));
	 * can be replaced with a malloc cll:
	 * 	a = malloc(n * sizeof(int));
	 * 
	 * Unlike calloc(), the function ma11oc() does not initialize the space
	 * in memory that it makes available. 
	 * 
	 * If there is no reason to initialize the array to zero, 
	 * then the use of either calloc() or malloc() is acceptable. 
	 * 
	 * In a large program, malloc() may take less time.
	 * 
	 * 
	 * */

	free(a);


	/**
	 * Space that has been dynamically allocated with either calloc() or malloc()
	 * does not get returned to the system upon function exit. 
	 * The programmer must use free() explicitly to return the space. 
	 * 
	 * A call of the form
	 * 	free(ptr)
	 * causes the space in memory pointed to by ptr to be deallocated. 
	 * If ptr is NULL, function has no effect. 
	 * If ptr is not NULL, it must be the base address of space 
	 * previously allocated by a call to calloc(), malloc(), or realloc() 
	 * that has not yet deallocated by a call to free() or realloc(). 
	 * 
	 * Otherwise, the call is in error. The effect of the error is system-dependent.
	 * */
	

	return 0;
}