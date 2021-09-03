#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void main(int argc, char *argv[]) 
/* get user input */
{
	char var1[15];
	char command[20];

	strcpy(command, "whois ");
	strcat(command, argv[1]);
	strcpy(var1, argv[1]);
	printf("Domain name : %s\n", var1);
	system(command);
}

/*
 --commaind to run and execute

gcc -o domain domain.c && ./domain brown.edu

*/