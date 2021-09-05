#include <stdio.h>

/*
Problem 19:

If you already solved the problem for finding the nth fibonacci number, 
then you must have a clear vision on how the program flow works.
So now, in this problem, print the values of your fibonacci function in pre-order, 
in-order and post-order traversal. 
For example, when n = 5, your program calls 3 and 4 from it, from the call of 3, 
your program calls 1 and 2 again....... here is the picture:

Input:
5
Output:
Inorder: 1 3 2 5 2 4 1 3 2
Preorder: 5 3 1 2 4 2 3 1 2
Postorder: 1 2 3 2 1 2 3 4 5

*/

void inOrderFib(int n) {
	if (n <= 2) {
		// leaf node, base case
		printf("%d ", n);
	} else {
		// compute left subtree
		inOrderFib(n - 2);

		// print in the middle 
		printf("%d ", n);

		// compute right subtree
		inOrderFib(n - 1); 
	}
}

void preOrderFib(int n) {
	if (n <= 2) {
		// leaf node, base case
		printf("%d ", n);
	} else {
		// print first 
		printf("%d ", n);

		// compute left subtree
		preOrderFib(n - 2);

		// compute right subtree
		preOrderFib(n - 1); 
	}
}


void postOrderFib(int n) {
	if (n <= 2) {
		// leaf node, base case
		printf("%d ", n);
	} else {
		// compute left subtree
		postOrderFib(n - 2);

		// compute right subtree
		postOrderFib(n - 1);

		// print last 
		printf("%d ", n); 
	}
}


int main(void) {

	int n;
	scanf("%d", &n);

	printf("Inorder: "); {
		inOrderFib(n); 
		printf("\n");
	}
	printf("Preorder: "); {
		preOrderFib(n); 
		printf("\n");
	}
	printf("Postorder: "); {
		postOrderFib(n); 
		printf("\n");
	}

	return 0;
}


// gcc -o recursion19 recursion19.c && ./recursion19
