#include <stdio.h>


/**
 * Pointer arithmetic is one of the powerful features of C.
 * 
 * If the variable p is a pointer to a particular type,
 * then the expression p + 1 yields the correct machine address for storing
 * or accessing the next variable of that type. 
 * 
 * In a similar fashion, pointer expressions such as 
 * p + i and ++p and p += i all make sense. 
 * 
 * If p and q are both pointing to elements of an array, then p - q yields 
 * the int value representing the number of array elements between p and q. 
 * 
 * Even though pointer expressions and arithmetic expressions have a similar appearance,
 * there is a critical difference in interpretation between the two types of expressions. 
 * 
 * The following code illustrates this:
 * */


int main() {

	double a[2], *p;

	double *q;

	p = a;			/* points to the base of array */
	q = p + 1;		/* equivalent to q = &a[1] or q = a + 1 */

	printf("sizeof (double) : %ld bytes\n", sizeof (double));

	printf("p : %p, q = %p\n", p, q); // print hex values which are the memory address pointed by p and q
	printf("p : %lu, q = %lu\n", (long unsigned int)p, (long unsigned int)q); // print int values containted in p and q

	printf("%ld\n", q - p); // 1 is printed
	printf("%ld\n", (long int)q - (long int)p); // 8 is printed

	/**
	 * On most machines, a double is stored in 8 bytes. 
	 * Because p points to a daub1e and q points to the next double, 
	 * the difference in terms of array elements is 1, 
	 * but the difference in memory locations is 8.
	 * 
	 * */

	return 0;
}