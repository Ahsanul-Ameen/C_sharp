#include "string_methods.h"


int main(void) {


	char 	s1[] = "beautiful big sky country",
		 	s2[] = "how now brown cow";

	printf("strlen(s1) :: %lu\n", strlen(s1));			// 25
	printf("strlen(s2 + 8) :: %lu\n", strlen(8 + s2));	// 9
	printf("strcmp(s1, s2) :: %d\n", strcmp(s1, s2));	// -6 (negative integer)
	printf("s1 + 10 :: %s\n" , s1 + 10);				// big sky country

	strcpy(s1 + 10, s2 + 8);	
	strcat(s1, "s!");

	printf("s1 :: %s\n", s1);							// beautiful brown cows!

	return 0;
}


// command : gcc string_methods.c main.c -o string.exe && ./string.exe