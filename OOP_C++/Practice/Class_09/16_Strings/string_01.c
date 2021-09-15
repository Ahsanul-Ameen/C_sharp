#include <stdio.h>


/**
 * Strings are one-dimensional arrays of type char. 
 * By convention, a string in C is terminated by the end-of-string sentinel \0, or null character. 
 * The null character is a byte with all bits off; hence, its decimal value is zero
 * 
 * char ch = '0'; // ASCII value is 48
 * 
 * int value = ch; // auto type casted value is 48 in decimal integer
 * 
 * But, 
 * 
 * char ch = '\0';	// ASCII value is 0
 * 
 * int value = ch; // auto type casted value is 0 as original value is forced by backslash
 * 
 * C strings are of variable length char array delimited by the "null" character '\0'
 * with a maximum length determined by the size of the string.
 * 
 * The SIze of a string must include the storage needed for the end-of-string sentinel.
 * 
 * String constants are written between double quotes.
 * 
 * For example, "abc" is a character array of size 4, 
 * with the last element being the null character \0. 
 * Note that string constants are different from character constants. 
 * For example, "a" and 'a' are not the same. 
 * The array "a" has two elements, the first with value 'a' and the second with value '\0'.
 * 
 * 
 * A string constant, like an array name by itself, is treated by the compiler as a pointer.
 * Its value is the base address of the string.
 * */

int main(void) {

	char *p = "abc";

	printf("%s %s\n", p, p + 1); /* abc bc is printed */

	/**
	 * The variable p is assigned the base address of the character array "abc". 
	 * When a pointer,to char is printed in the format of a string, 
	 * the pointed-at character and each successlve character are printed 
	 * until the end-of-string sentinel is reached. 
	 * Thus, in the printf() statement, the expression p causes abc to be printed, 
	 * and the expression p + 1 which points to the letter b in the string "abc", 
	 * causes bc to be printed,
	 * 
	 * 
	 * 
	 * AS a strmg constant such as "abc" is treated as a pointer, we can write...
	 * */

	char ch = "abc"[1];	// allowed

	char dh = *("abc" + 2); // allowed

	printf("%c %c\n", ch, dh);	// b c is printed -> 2nd and 3rd character of "abc"


	return 0;
}