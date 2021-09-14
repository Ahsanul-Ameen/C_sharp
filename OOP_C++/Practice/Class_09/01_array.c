#include <stdio.h>

#define MAXN 100


int global_array[MAXN / 20];

void printArray(int arr[], int n) {
	int i = 0;
	while(i < n) {
		printf("%d ", arr[i++]);
	}
	printf("\n");
}


void pass(int p) {
	printf("Pass %d--------------------\n", p);

	printf("global_array: ");
	printArray(global_array, MAXN / 20);

	int uninitialized_array[MAXN / 20];
	printf("uninitialized_array: ");
	printArray(uninitialized_array, MAXN / 20);

	int initialized_array[MAXN / 20] = {5, 55, 555, 55, 5};
	printf("initialized_array: ");
	printArray(initialized_array, MAXN / 20);

	int zeroized_array[MAXN / 20] = {0};
	printf("zeroized_array: ");
	printArray(zeroized_array, MAXN / 20);


	int n = 4;
	int arr[n];
	printf("uninitialized_array of size n: ");
	printArray(arr, n);
}


int main(void) {


	for(int i = 1; i <= 5; ++i) {
		pass(i);
		printf("\n");
	}

	char name[] = "\"Green Tea of Srimangal!\"";
	printf("name(array of chars): %s\n", name);
	

	return 0;

}