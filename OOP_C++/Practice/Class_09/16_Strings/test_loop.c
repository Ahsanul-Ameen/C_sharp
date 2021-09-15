#include <stdio.h>

int main(void) {
	
	int a = 0, b = 6;

	while (a++ <= b--) // 0 6 (true), 1 5 (true), 2 4(true), 3 3(true), 4 5 (false)
		;				// after falsification value changed to 5 1

	printf("a = %d, b = %d\n", a, b);	// prints a = 5, b = 1



	return 0;
}


/**
 * Run Command : 	gcc test_loop.c -o test_loop.exe && ./test_loop.exe
 * */