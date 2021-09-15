#include "string_methods.h"



size_t strlen(const char *s) 
{
	size_t n;

	for (n = 0; *s != '\0'; ++s) 
		++n;

	return n;
}


char *strcpy(char *s1, register const char *s2)
{
	register char *p = s1;
	
	while (*p++ = *s2++)		// *p++ is equivalent to *(p++) not (*p)++ as ++ has higher precedence than *
		;						// value of expression p++ is the current value of p
								// the value is dereferenced; (here also the value of *s2 is assigned to it) 
								// then then value of p in memory is incremented...
								// as right side execute first so
								// value of s2 is dereferenced and obtained as the value of the expression
								// then s2 = s2 + 1 (as usual implicitly for s2++)
								// *p gets the value of the right expression
								// after p is incremented, the newly assigned value is returned
								// as the value of the expression
								// if it is '\0' then the loop breaks

	return s1;
}


char *strcat(char *s1, register const char *s2)
{
	register char *p = s1;
		
	while (*p)				// same as -> while (*p != '\0')
		++p;				/* go to the end */

	while (*p++ = *s2++)	/* copy */
		;				
	return s1;
}


int strcmp(register const char *s1, register const char *s2)
{
	while (*s1 == *s2)			/* move until mismatch found */
		++s1, ++s2;				/* don't use < while (*s1++ == *s2++); >, see test_loop.c for more details */
	
	return (*s1 - *s2);			/* diff can be -ve or zero or +ve */
}