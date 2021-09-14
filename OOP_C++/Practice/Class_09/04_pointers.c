#include <stdio.h>

/**
 * A pointer can be initialized in a declaration. 
 * The variable p is of type (int *) and its initial value is &i. 
 * Also, the declaration of i must occur before we take its address.
 * Actual location of a variable in memory is system-dependent. 
 * The operator * derefences p. 
 * That is, p contains an address, or location, 
 * and the expression *p has the value of what is stored at this location 
 * appropriately interpreted according to the type 	declaration of p.
 * 
 * */

int main(void) {

	/* Printing an address, or location. */


	int i = 8, *p = &i; 

	printf("%s%d\n%s%p\n", "Value of i: ", *p, 
							"Location of i: ", p);


	return 0;
}