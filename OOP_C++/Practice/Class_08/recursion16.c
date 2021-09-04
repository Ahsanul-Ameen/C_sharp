#include <stdio.h>
#include <string.h>

#define MAXN 100

/*
Problem 16:

Read a string from keyboard and print it in reversed order.
You must not use any array to store the characters. 
Write a recursive solutions to solve this problem.

Input:
helloo
Output:
oolleh

*/

void printReverseStr(char* str, int n) {
	if (n == 0) {
		printf("\n");
		return;
	}

	printf("%c", str[n - 1]);
	printReverseStr(str, n - 1);
}

int main(void) {

	char str[MAXN];
	scanf("%s", str);
	printReverseStr(str, strlen(str));

	return 0;
}

 
// gcc -o recursion16 recursion16.c && ./recursion16