#include <stdio.h>
#include <stdlib.h>

int main(void) 
{

    int a[30][20]; // declare an int array of two dimension
    // consider it as 30 rows of one dimensional array of size 20
    /**
     * 00 -------1st row contains 20 elements-------
     * 01 -------2nd row     "     "     "   -------
     * .............................................
     *         .             ...   .... 
     *         .             ...   ...   
     * .............................................
     * 28 -------29th row contains 20 elements------
     * 29 -------30th (last) row -------------------
     * **/


    // demo of expressions equivalent to a[i][j]
    // access the content of the cell at ith row and jth column : a[i][j]

    int i, j;

    for (i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
        for (j = 0; j < sizeof(a[0]) / sizeof(a[0][0]); ++j) {
            // go to j steps ahead from the beginning of ith row
            // assign value i + j using dereference operator
            *(a[i] + j) = i + j;

            // read the value just assigned
            int cell = (*(a + i))[j];

            int same_cell = *((*(a + i)) + j);

            int same_cell_value = *(&a[0][0] + 20 * i + j);

            int val = a[i][j] = *(*a + 20 * i + j) = *(a[0] + 20 * i + j) = *((int*)&a[0] + 20 * i + j);

            if (a[0] != (int *)&a[0] || cell != same_cell || same_cell != same_cell_value || val != cell) {
                printf("Error at cell %d %d\n", i, j);
                exit(1);
            }

           
            printf("cell %d, %d : %d\n", i, j, cell);
        }
    }

    /**
     * The parentheses are necessary because the brackets [] 
     * have higher precedence than the indirection operator *.
     * 
     * We can think of a[i] as the ith row of array a (counting from 0)
     * and we can think of a[i][j] as the element in the ith row, 
     * jth column of the array (counting from 0). 
     * 
     * The array name a by itself is equivalent to &a[0]; 
     * it is a pointer to an array of 20 ints. 
     * 
     * The base address of the array is &a[0][0], not a. 
     * Starting at the base address of the array, 
     * the compiler allocates contiguous space for 600 ints.
     * 
     * 
     * For any array, the mapping between pointer values 
     * and array indices is called the storage mapping (unction. 
     * 
     * Consider the declaration
     *          int a[3][5];
     * 
     *  For array a, the storage mapping function is specified as 
     * 
     *      a[x][y]    is equivalent to   *(&a[x][y] + x * 5 + y)
    */


    return 0;
}