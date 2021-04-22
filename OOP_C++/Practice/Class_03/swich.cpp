#include <stdio.h>


// no if-else usage
int main() {
	int marks;
	bool fail = false; 

	do {


		scanf("%d", &marks);
		printf("marks = %d\n", marks);

		switch (marks/10) {
			case 10:
			case 9:
			case 8:
				puts("A+"); 
				break;
			case 7:
				puts("B"); 
				break;
			case 6:
			case 5:
				puts("C"); 
				break;
			case 4:
			case 3:
				puts("D"); 
				break;

			default: 
				puts("FAIL");
				fail = true;
				break;
		}
	} while (!fail);

	

	


	//80  - 100 A+
	//70 -  79  B
	//50 -  69  C
	//30 -  49  D
	// FAIL

	return 0;
}