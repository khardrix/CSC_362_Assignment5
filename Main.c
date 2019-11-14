#include <stdio.h>


/* -------------------------------------------------- FUNCTION PROTOTYPES ------------------------------------------------- */

/* ----------------------------------------------- END OF FUNCTION PROTOTYPES --------------------------------------------- */


// main function where program execution begins
int main() {

	/* ------------------------------------------------ VARIABLE DECLARATIONS ------------------------------------------------- */
	// int array to be sorted (two versions, each for its own run of the program)
	int a[] = {100, 99, 97, 95, 90, 87, 86, 83, 81, 77, 74, 69, 63, 50, 44, 43, 39, 31, 29, 12}; // for 1st run
	// int a[] = {8, -1, 7, -8, 6, 3, -4, 4, 1, -2, 9, -5, 0, 2}; // for 2nd run

	// int variable to store the current minimum int value
	int min;
	// int variable to store the index of the current minimum int value
	int minPosition;

	// int variable to temporarily store the value of the minimum int value 
		// (used to swap int value elements around in order to sort them in increasing order)
	int temp;

	// int counter variables used in for loops
	int i;
	int j;

	// int variable to store the number of elements in the int array variable, "a"
	int n = (sizeof(a) / sizeof(int));
	/* -------------------------------------------- END OF VARIABLE DECLARATIONS ---------------------------------------------- */

	// printf("The number of elements in int array \"a\" = %d \n", n);

	// for loop to loop through all the elements in the int array "a" and 
		// store the minimum value in each loop in order to sort the array
	for (i = 0; i < (n - 1); i++) {
		// store the value in the current index of the int array "a" to the int variable "min" 
		min = a[i];
		// store the current value of the int counter variable "i" to the int variable "minPosition" 
			// ("minPosition" stores the index of the current minimum value in the int array "a")
		minPosition = i;

		// inner for loop used to loop through the entire int array "a" and 
			// find the minimum int value that hasn't been sorted yet
		for (j = (i + 1); j < n; j++) {
			// if statement to check if the current int element value is the smallest of the unsorted elements
				// and store that value and index to their respective variables
			if (a[j] < a[minPosition]) {
				// store the int value of the minimum int element (that hasn't been sorted yet) 
					// in the int array "a" to the int variable, "min"
				min = a[j];
				// store the index of the minimum value in the int array "a" that hasn't been sorted yet
				minPosition = j;
			}
		}
		// the next three steps swaps the int values around in order to put the int array "a" in ascending order
		// store the value of the "i-th" element to the "temp" variable
		temp = a[i];
		// store the value at the "minPosition" index to the "i-th" index in the int array "a"
		a[i] = a[minPosition];
		// store the value of the "i-th" element (stored in "temp" variable) 
			// to the "minPosition" index of the int array "a"
		a[minPosition] = temp;
	}

	// for loop to print out the int array, "a"
	for (i = 0; i < n; i++) {
		// print the current int element value, followed by a comma and a space to the terminal
		printf("%d, ", a[i]);
	}


	// return 0 to indicate the program executed completely with no errors
	return 0;
}


/*
Output:
First run:
12, 29, 31, 39, 43, 44, 50, 63, 69, 74, 77, 81, 83, 86, 87, 90, 95, 97, 99, 100,
C:\Users\user\source\repos\Huffman_Ryan_CSC_362_Assignment_5\Debug\Huffman_Ryan_CSC_362_Assignment_5.exe (process 8028) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

Second run:
-8, -5, -4, -2, -1, 0, 1, 2, 3, 4, 6, 7, 8, 9,
C:\Users\user\source\repos\Huffman_Ryan_CSC_362_Assignment_5\Debug\Huffman_Ryan_CSC_362_Assignment_5.exe (process 18228) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/