#include <stdio.h>


/**
 * In a function definition, a formal parameter that is declared as an array is actually pointer. 
 * Corresponding to this, when an array is passed as an argument to a function
 * the base address of the array is passed "call-by-value." 
 * 
 * The array elements themselves are not copied. 
 * 
 * As a notational convenience, the compiler allows array bracket to be used 
 * in declaring pointers as parameters.
 * To illustrate these ideas, we write a function that sums the elements of an array of type double.
 * */

double sum(double a[], int n) /* n is the size of a[] */
{
	int i;

	double sum = 0.0;

	for (i = 0; i < n; ++i)
		sum += a[i];

	return sum;
}


/**
 * Note carefully that in the header to the function definition the declaration of the 
 * parameter a as an array is equivalent to its declaration as a pointer. 
 * This means that equivalent function definition is given by
 * 
 * 	double sum(double *a, int n)  
 *  {
 * 		...
 * 
 * would do the same!
 * 
 * Although an array declaration is equivalent to a pointer declaration in a parameter list,
 * this equivalence does not hold for external declarations or for declarations 
 * within the body of a function.
 * */


int main(void) {

	double v[100];

	for (int i = 0; i < 100; ++i)
		*(v + i) = i;

	// compute v[0] + v[1] + ...c... + v[99] and returned
	double s = sum(v, 100); 
	printf("sum(v, 100) = %lf\n", s); // here v[0] + v[1] + ... + v[0 + 100 - 1]


	// compute v[0] + v[1] + ...c... + v[87] and returned
	s = sum(v, 88); 
	printf("sum(v, 88) = %lf\n", s); // here v[0] + v[1] + ... + v[0 + 88 - 1]


	int k = 10;
	// compute v[7] + v[8] + ...c... + v[k - 1] and returned
	s = sum(&v[7], k - 7); 
	printf("sum(&v[7], k - 7) = %lf\n", s); // here v[7] + v[8] + v[7 + (10 - 7) - 1]


	// compute v[7] + v[8] + ...c... + v[2k + 6] and returned
	s = sum(v + 7, 2 * k); 
	printf("sum(v + 7, 2 * k) = %lf\n", s); // here v[7] + v[8] + ... + v[7 + (2 * 10) - 1]

	/**
	 * The last call illustrates again the use of pointer arithmetic. 
	 * The base address of v is offset by 7, 
	 * causing the local pointer variable a in sum() to be initialized to this value.
	 * 
	 * This causes all address calculations inside the function call to be similarly offset.
	 * */



	return 0;
}