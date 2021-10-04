#include <stdio.h>
#include <stdlib.h>


void recursion() {
	static char ch = 'a';
	static char *cp = &ch;

	if(*cp <= 'z') {
		printf("%c\n", ch);
		(*cp)++;
		recursion();
	}
}


int f(int i)
{
    char *dp;    /* dp is a wild pointer */
    static char *scp;  /* scp is not a wild pointer:
                        * static variables are initialized to 0
                        * at start and retain their values from
                        * the last call afterwards.
                        * Using this feature may be considered bad
                        * style if not commented */

	printf("%p \t %p\n", dp, scp);
}


int main(void) {
	

	recursion();

	// now we understand what is a static pointer

	// -------------------------------------------

	/**
	 * Wild pointers are created by omitting necessary initialization prior to first use.
	 * Thus, strictly speaking, every pointer in programming languages which do 
	 * not enforce initialization begins as a wild pointer.
	 * 
	 * This most often occurs due to jumping over the initialization, not by omitting it.
	 * Most compilers are able to warn about this.
	 * */

	f(5);


	return 0;
}


// gcc 03_wild_pointers.c -o 03_wild_pointers.exe && ./03_wild_pointers.exe