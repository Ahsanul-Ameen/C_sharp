/** Count the number of words in a string */

#include <stdio.h>
#include <ctype.h>

#define MAXN 100

int word_cnt(const char *s) {
	int cnt = 0;

	while (*s != '\0') {		/* until the end of string */
		while (isspace(*s))
			++s;				/* skip white space */

		if (*s != '\0') {
			++cnt;				/* found a word */
			
			while (!isspace(*s) && *s != '\0') 
				++s;			/* skip the word */
		}	
	}

	return cnt;
}

int main(void) {

	printf("enter a sentence: ");

	char str[MAXN];

	scanf("%[^\n]s",str);	// read unto newline

	printf("\n\"%s\" has %d words\n", str, word_cnt(str));

	return 0;
}