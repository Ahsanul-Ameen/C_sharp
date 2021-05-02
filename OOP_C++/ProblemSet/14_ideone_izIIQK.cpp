#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
	Read the comments carefully. At this moment, you should fully understand the basic string operations (without proper memory allocation versions). 
	Try to understand what is done in memory safe implementations.
*/
/**
	I was wrong about the allocation of null character. If you need to store the null character, you should allocate one extra byte for this
*/
int mystrlen(char* str)
{
    int len=0;
    while(*str!='\0')
    {
        str++;
        len++;
    }
    return len;
}

/**
without proper memory allocation
*/
void mystrcat(char* str1, char* str2)
{
    while(*str1!='\0')
    {
        str1++;
    }
    while(*str2!='\0')
    {
        *str1 = *str2;
        str2++;
        str1++;
    }
    *str1 = '\0';
}

/**
	memory safe version
*/
void mystrcat_mem(char* str1, char* str2)
{
	/**
		We need to reallocate memory for str1. So, previous memory address must be saved.
	*/
	int length = mystrlen(str1)+mystrlen(str2);
	
	/**
		1 additional for NULL character.
		realloc: used to re-allocate (size increase/decrease) the same memory 
	*/
	str1 = (char*) realloc(str1,(length+1)*sizeof(char));
	
	/**
		For previous contents, let it stay as it is
	*/
    while(*str1!='\0')
    {
		str1++;
    }
	/**
		Now copy the contents of str2 to str1
	*/
    while(*str2!='\0')
    {
        *str1 = *str2;
        str2++;
        str1++;
    }
    *str1 = '\0';
}

/**
without proper memory allocation
*/
void mystrcpy(char* str1, char* str2)
{
    while(*str2!='\0')
    {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
}

/**
with memory allocation
*/
void mystrcpy_mem(char* str1, char* str2)
{
	/**
		Extra 1 byte for NULL character
	*/
	str1 = (char*) realloc(str1,(mystrlen(str2)+1)*sizeof(char));
	
    while(*str2!='\0')
    {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
}

char* mysubstr(char* str, int first, int last)
{
    if(first>=mystrlen(str)) return NULL;
    if(last>=mystrlen(str))
    {
        last = mystrlen(str)-1;
    }
	/**
		Determining size:
			how many characters between first and last index? answer is (last-first+1)
			1 additional character for storing null character
			So, total (last-first+1)+1 = last-first+2 characters
	*/
    char* newStr = (char*) malloc(sizeof(char)*(last-first+2));

	/**
		As, the (starting)address of newStr is changed, we need to hold the previous address to return the entire string
	*/
    char* ret = newStr;

    int idx=0;
    while(idx<first)
    {
        str++;
        idx++;
    }

    while(idx<=last)
    {
        *newStr = *str;
        newStr++;
        str++;
        idx++;
    }

    *newStr = '\0';

    return ret;
}

int mystrcmp(char* str1, char*str2)
{
	/**
		Skip while characters of both strings are equal. The loop terminates in 2 ways:
			--two characters are not equal
			--any of the character is null (at least one string is terminated)
	*/
    while(*str1==*str2)
    {
        if(*str1=='\0' || *str2=='\0') break;
        str1++;
        str2++;
    }
	/**
		Both string terminated and before they were equal always. So, EQUAL
	*/
    if(*str1==*str2) return 0;
	/**
		(1)All chacters were equal upto this point. str2 terminated and str1 is not terminated.
		ex: abcd , abc -> abc is smaller -> abcd is greater
		(2) Characters are not equal and character of str1 is greater than that of str2.
		ex: abd , abc -> abd is greater
	*/
    else if(*str2=='\0' || *str1>*str2) return 1;
	/**
		See prev. comment
	*/
    else if(*str1=='\0' || *str1<*str2) return -1;
}

int main(void)
{
    char *str;
    str = (char *) malloc(50*sizeof(char));
    printf("Please Enter a string: ");
    gets(str);
    printf("String Length = %d\n",mystrlen(str));

    char *str2 = (char*) malloc(50*sizeof(char));
    printf("Please Enter another string: ");
    gets(str2);

    mystrcat_mem(str,str2);
    printf("Concatenated string: %s\n",str);

    mystrcpy_mem(str,str2);
    printf("After Copy: %s\n",str);

    char *substr = mysubstr(str,2,5);
    printf("Substring: %s\n",substr);

    printf("Please Enter a string: ");
    gets(str);
    printf("Please Enter another string: ");
    gets(str2);
    printf("%d\n",mystrcmp(str,str2));

    return 0;
}