#include <stdio.h>

#define MAXN 100

/*
Problem 18:

Implement strcat(), stracpy(), strcmp() and strlen() recursively.

Input:
test on your own
Output:
test on your own

-------nota bene : This implementation is tested aginst a small number of test case
					So potential BUGS might occur
					I suggest you to review the code and point out the corner cases (if any)
					Otherwise try and test in random test cases

					Also note that these implementations are non-recursive
					Try to do it using recursion :)
					
*/


size_t m_strlen(const char *str) {
	size_t len = 0;
	while (str != NULL && *str != '\0') ++str, ++len;
	return len;
}

char* strcpy(char* destination, const char* source) {
	char *head = destination;
	while (source != NULL && *source != '\0') *destination++ = *source++;
	*destination = '\0';
	return head;
}

// the destination should be large enough to contain
// the concatenated resulting string
char *m_strcat(char *destination, const char *source) {
	char *ptr = destination + m_strlen(destination);
	
	// while (source != NULL && *source != '\0') *ptr++ = *source++;
	// *ptr = '\0';

	strcpy(ptr, source);

	return destination;
}

int m_strcmp (const char* str1, const char* str2) {

	if (!str1 && str2) return -1;
	else if (str1 && !str2) return +1;
	else if (!str1 && !str2) return 0;

	while (*str1 != '\0' && *str1 == *str2) ++str1, ++str2;
	

	if (*str1 != '\0' && *str2 == '\0') return +1;
	else if (*str1 == '\0' && *str2 != '\0') return -1;
	else return *str1 - *str2;
}

int main(void) {

	char lstr[MAXN] = "hablu";
	char *rstr = "bablu";

	printf("m_strlen(\"422342asdf\\n\\0haha\") : %lu\n", m_strlen("422342asdf\n\0haha"));

	printf("m_strlen(lstr) : %lu\n", m_strlen(lstr));
	printf("m_strlen(rstr) : %lu\n", m_strlen(rstr));

	char *lrstr = m_strcat(lstr, rstr); // destination should have enough bytes allocated

	printf("\nm_strlen(lstr) : %lu, m_strlen(rstr) : %lu, m_strlen(lrstr) : %lu\n", m_strlen(lstr), m_strlen(rstr), m_strlen(lrstr));
	printf("lstr : %s\nrstr : %s lrstr : %s\n", lstr, rstr , lrstr);

	char *name = strcpy(lrstr, "Voldemort ");
	printf("\nname : %s\nlrstr : %s\n", name, lrstr);
	strcpy(name, rstr);
	printf("name : %s\nlrstr : %s\n", name, lrstr);



	char str1[] = "abcd", str2[] = "abCd", str3[] = "abcd";
	int result;

	// comparing strings str1 and str2
	result = m_strcmp(str1, str2);
	printf("\nm_strcmp(str1, str2) = %d\n", result);

	// comparing strings str1 and str3
	result = m_strcmp(str1, str3);
	printf("m_strcmp(str1, str3) = %d\n", result);

	
	
	char leftStr[] = "g f g";
    char rightStr[] = "g f g";
      
    // Using m_strcmp()
    int res = m_strcmp(leftStr, rightStr);
      
    if (res==0)
        printf("Strings are equal");
    else 
        printf("Strings are unequal");
      
    printf("\nValue returned by m_strcmp() is:  %d\n" , res);
    
	printf("%d\n", m_strcmp("zfz", "gfg"));
	printf("%d\n", m_strcmp("bfb", "bfg"));
	printf("%d\n", m_strcmp("abcdefg_+-*/", "abcdefg_+-*/"));
	printf("%d\n", m_strcmp("", "asdfs"));

	printf("%d\n", m_strcmp("1905047", "191"));
	
	return 0;
}


// gcc -o recursion18_ recursion18_.c && ./recursion18_
