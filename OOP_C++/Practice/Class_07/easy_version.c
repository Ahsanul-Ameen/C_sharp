#include <stdio.h>

void fillArray(int *arr, const int n, const int value);
void printTriangle(const int n);
void printAlignedTriangle(const int n);
void printPatternOptimizedMem(const int n);


int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Please enter the size of Pascal's triangle\n");
		return 1; 
	}
	int n = atoi(argv[1]); // convert const char array to int using the argument vector

	// 1. print triangle without any memory optimization
	printTriangle(n);

	// 2. print aligned triangle without any memory optimization
	printAlignedTriangle(n);

	// 3. print aligned pattern with memory optimization (Quadratic n by n to Linear 2 by n)
	printPatternOptimizedMem(n);
}


// fill up the 2D array of n by n with value 
void fillArray(int *arr, const int n, const int value) {
	for(int r = 0; r < n; r++) 
		for(int c = 0; c < n; c++) 
			*(arr + r * n + c) = value;
}


void printTriangle(const int n) {
	// create a 2D array of size n by n
	int triangle[n][n];

	// set initial value to zero
	// remember that arrays are passed by reference
	// cast the 2D array to a 1D array pointer
	fillArray((int *)triangle, n, 0);

	for(int r = 0; r < n; r++) {
		for(int c = 0; c <= r; c++) {
			// remember the rule of cell value...
			triangle[r][c] = !c ? 1 : triangle[r - 1][c - 1] + triangle[r - 1][c];			
			printf("%d ", triangle[r][c]);
		}
		printf("\n");
	}
	printf("\n");
}


void printAlignedTriangle(const int n) {
	/**
	  	1
		1 1
		1 2 1
		1 3 3 1 
		1 4 6 4 1 
		1_5_10 10 5 1 // put appropriate spaces first
	 */

	// create a 2D array of size n by n
	int triangle[n][n];

	// set initial value to zero
	// remember that arrays are passed by reference
	// cast the 2D array to a 1D array pointer
	fillArray((int *)triangle, n, 0);

	for(int r = 0; r < n; r++) {
		// print n - 1 - r spaces first
		for(int i = 0; i < n - r - 1; ++i)
			printf("  "); // put two spaces
		for(int c = 0; c <= r; c++) {
			// remember the rule of cell value...
			triangle[r][c] = !c ? 1 : triangle[r - 1][c - 1] + triangle[r - 1][c];		
			// "%<minimum-characters-overall>.<minimum-digits>d"	
			printf("%2.1d  ", triangle[r][c]);
		}
		printf("\n");
	}
	printf("\n");
}


void printPatternOptimizedMem(const int n) {
	// create a 2D array of size 2 by n 
	// we only need the previous row to calculate any new row
	// hence two rows will be enough for computation
	int triangle[2][n];

	// initialize to zero
	for(int i = 0; i < n; i++)
		triangle[0][i] = triangle[1][i] = 0;

	for(int r = 0; r < n; r++) {

		// print n - 1 - r spaces first
		for(int i = 0; i < n - r - 1; ++i)
			printf(" "); // put gaps/other

		for(int c = 0; c <= r; c++) {
			// remember the rule of cell value...
			// here we've changed it to XOR operation 
			// so cell values will be limited to {0, 1} set
			// use the concept of odd/even row  
			// (if r is even then (r - 1) is odd) and vice versa
			triangle[r % 2][c] = !c ? 1 : triangle[(r - 1) % 2][c - 1] ^ triangle[(r - 1) % 2][c];		
			printf("%c", triangle[r & 1][c] ? '+' : '-'); // (n % 2) is same as (n & 1)
			printf(" ");
		}

		printf("\n");
	}

}