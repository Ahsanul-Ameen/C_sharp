#include <stdio.h>

/**
 * HeadNote : All of the methods discussed here are implemented in the 
 * 			  C standard header file string.h
 *
 * So we can use these methods by just putting #include <string.h>
 * 											or #include <cstring> (probably in .cpp files)
 * */

/**
 * STRing conCATanation method
 * 
 * @arg1: string s1
 * @arg2: string s2
 * 
 * concatenates them, puts the result in s1.
 * the programmer must ensure that s1 points to enough space to hold the result.
 * 
 * @return: the pointer s1 (as s1 = s1 + s2 as C++ strings in STL)
 * */
char *strcat(char *s1, const char *s2);


/**
 * STRing CoMParison method
 * 
 * @arg1: string s1
 * @arg2: string s2
 * 
 * 
 * @return: an integer less than | equal to | greater than zero
 * 
 * Depending on whether s1 is lexicographically less than, equal to or greater than s2 		
 * */
int strcmp(const char *s1, const char *s2);


/**
 * STRing CoPY method
 * 
 * @arg1: string s1
 * @arg2: string s2
 * 
 * The characters in the string s2 are copied into s1 until \0 is moved.
 * whatever exists in s1, is overwritten.
 * the programmer must ensure that s1 points to enough space to hold the result.
 * 
 * @return: the pointer s1 (as s1 = s2)
 * */
char *strcpy(char *s1, const char *s2);



/**
 * STRing LENgth method
 * 
 * @arg: string s
 * 
 * A count of the number of characters before \0 is returned.
 * ANSI C requires the type size_t to be an integral unsigned type.
 * Typically, on 4 byte systems it is equivalent to unsigned int and (though in my machine long unsigned int)
 * 													unsigned long for 2 byte systems
 * 
 * @return: the pointer s1 (as s1 = s2)
 * */
size_t strlen(const char *s);