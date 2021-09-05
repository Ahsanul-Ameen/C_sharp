#include <stdio.h>

/*
Problem 20:

https://www.khanacademy.org/computing/computer-science/algorithms/towers-of-hanoi/a/towers-of-hanoi

All of you have seen the tower of Hanoi. 
You have 3 pillars 'a', 'b' and 'c', and you need transfer all disks from one pillar to another. 
Conditions are, only one disk at a time is movable, 
and you can never place a larger disk over a smaller one. 
Write a recursive solution to print the moves that simulates the task, 
a -> b means move the topmost of tower a to tower b.

Input:
3
Output:
a -> c
a -> b
c -> b
a -> c
b -> a
b -> c
a -> c

*/

void tHanoiMove(int height, char src, char auxiliary, char dst) {
	if (height <= 0) 
		return; // nothing to move
	// move top tiles except the last one to auxiliary tower
	tHanoiMove(height - 1, src, dst, auxiliary);
	// move the bottom most tiles to dst
	printf("%c -> %c\n", src, dst);
	// move all the tiles from auxiliary to dst
	tHanoiMove(height - 1, auxiliary, src, dst); 
}


int main(void) {

	int height;
	scanf("%d", &height);

	tHanoiMove(height, 'a', 'b', 'c'); // move all tiles from a to c using auxiliary tower b

	return 0;
}


// gcc -o recursion20 recursion20.c && ./recursion20
