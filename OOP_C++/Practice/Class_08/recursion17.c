#include <stdio.h>
#include <string.h>

#define MAXN 100

/*
Problem 17:

Write a recursive program that determines whether a given sentence is palindromic or not just considering the
alpha-numeric characters ('a'-'z'), ('A'-'Z'), ('0'-'9').

Input:
madam, i'i ,madam
hulala
Output:
palindromic
not palindromic

*/


int main(void) {

	int isPalindromic(char *str, int l, int r) {
		if (l >= r) return 1;

		if (str[l] != str[r])
			return 0;
		return isPalindromic(str, l + 1, r - 1);
	}

	char str[MAXN];
	// follow this link : https://stackoverflow.com/questions/6282198/reading-string-from-input-with-space-character

	scanf("%[^\n]s", str); // \n just sets the delimiter for the scanned string.

	int status = isPalindromic(str, 0, strlen(str) - 1);

	printf("%s\n", status ? "palindromic" : "not palindromic");

	return 0;
}


// gcc -o recursion17 recursion17.c && ./recursion17
