#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main() {
	srand(time(NULL));

	char *p = "abcde"; // 4 bytes for p, 6 bytes for allocated "abcde" 

	char s[] = "abcde"; // 6 bytes of data for s 
						// as if {'a', 'b', 'c', 'd', 'e', '\0'}

	char *cs;
	int nfrogs;

	nfrogs = rand() % 3 + 1; // get nfrogs from somewhere

	cs = (nfrogs == 1) ? "" : "s";
	printf("We found %d frog%s in the pond\n", nfrogs, cs);




	return 0;
}