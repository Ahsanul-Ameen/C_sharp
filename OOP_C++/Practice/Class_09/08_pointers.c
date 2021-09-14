#include <stdio.h>

/**
 * An array name by itself is an address, or pointer value,
 *  and pointers, as well as arrays,can be subscripted.
 * 
 * Although pointers and arrays are almost synonymous in terms of 
 * how they are used to access memory, there are differences, 
 * and these differences are subtle and important.
 * 
 * A pointer variable can take different addresses as values.
 * 
 * In con-trast, an array name is an address, or pointer, that is fixed. (a const pointer)
 * 
 * Suppose a is an array and i is an int,
 * Then,
 *       a[i] is equivalent to *(a + i)
 * 
 * The expression a [i] has the value of the ith element of the array (counting from 0)
 * 	 
 * whereas *(a + i) is the dereferencing of the expression a + i, 
 * a pointer expression that points i element positions past a.
 * 
 * Similarly if p is a pointer, 
 * 
 * Then, p[i] is equivalent to *(p + i)
 * 
 * This means that we can (and do) use array notation with pointers.
 * 
 * 
 * Expressions such as a + i and p + i are examples of pointer arithmetic. 
 * The expression a + i has as its value the ith offset from the base address 
 * of the array a. That is, it points to the ith element of the array (counting from 0).
 * In a similar manner, p + i is the ith offset from the value of p. 
 * The actual address produced by such an offset depends on the type that p points to.
 * 
 * 
 * When an array is declared, the compiler must allocate a sufficient amount 
 * of contiguous space in memory to contain all the elements of the array. 
 * The base address of the array is the initial location in memory where the array 
 * is stored; it is the address of the first element (index 0) of the array.
 * 
 * 
 * */


#define		N 	100

int a[N], i, *p, sum = 0;



int main(void) {

	p = a;

	p = &a[0]; // equivalent code snippet


	p = a + 1;

	p = &a[1]; // equivalent statement


	{
		a[40] = a[50] = 22;
	}


	// compute the sum of the array

	for (p = a; p < &a[N]; ++p) 
		sum += *p;

	/**
	 * First p is initialized to the base address of the array. 
	 * In the body of the loop, the variable sum is incremented by the value pointed to by p.
	 * Each time through the loop, p is incremented, 
	 * so its successive values are &a[0], &a[1], ... , &a[N-1].
	 * 
	 * */

	printf("sum : %d\n", sum);


	// another way of summing the array

	for (i = 0, sum = 0; i < N; ++i)
		sum += *(a + i);

	/**
	 * In the body of the loop the pointer value a is offset by i and then dereferenced.
	 *  This produces the value a[i].
	 * */

	printf("sum : %d\n", sum);



	// Finally, here is a third way

	p = a;

	for (i = 0, sum = 0; i < N; ++i) {
		sum += p[i];
	}

	printf("sum : %d\n", sum);


	// So what do you think of that?
	{
		a[N - 1] = a[0] = -5;
	}

	for (sum = 0, p = a + N - 1; p > a - 1; --p) {
		sum += *p;
	}

	printf("sum : %d\n", sum);




	return 0;
}