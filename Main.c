#include <stdio.h>

/*****************************************************************************************************************************************
 *****************************************************************************************************************************************
 *****    Class: CSC-362-001             Semester: Fall 2019             Professor: Richard Fox             Student: Ryan Huffman    *****
 *****-------------------------------------------------------------------------------------------------------------------------------*****
 *****                              Programming Assignment #5: Selection Sort Algorithm (inline x86 Assembly)                        *****
 *****_______________________________________________________________________________________________________________________________*****
 *****                           This program uses inline x86 Assembly to execute the Selection Sort algorithm                       *****
 *****                                               All the variables are declared in C.                                            *****
 *****                                                                                                                               *****
 *****                                                     The rest of the code                                                      *****
 *****                  (executing the Selection Sort algorithm to sort an unsorted int array into ascending order)                  *****
 *****                                                   is done in x86 Assembly.                                                    *****
 *****                                                                                                                               *****
 ***** The program then uses a mixture of inline Intel x86 Assembly Language and C to print all the int values inside the int array. *****
 *****************************************************************************************************************************************
 *****************************************************************************************************************************************/


 // main function where program execution begins
void main() {

	/* ------------------------------------------------ VARIABLE DECLARATIONS ------------------------------------------------- */
	// int array to be sorted (two versions, each for its own run of the program)
	int a[] = { 100, 99, 97, 95, 90, 87, 86, 83, 81, 77, 74, 69, 63, 50, 44, 43, 39, 31, 29, 12 }; // for 1st run
	// int a[] = {8, -1, 7, -8, 6, 3, -4, 4, 1, -2, 9, -5, 0, 2}; // for 2nd run

	// int variable to store the current minimum int value
	int min;
	// int variable to store the index of the current minimum int value
	int minPosition;

	// int variable to temporarily store the value of the minimum int value 
		// (used to swap int value elements around in order to sort them in increasing order)
	int temp;
	int tempTwo;

	// int counter variables used in for loops
	int i;
	int j;

	// int variables used for comparison
	int first;
	int second;

	// int variable used for printing the int element currently being worked with
	int current;

	// int variable used to move indexes inside the array
	int four = 4;

	// int variable to store the number of elements in the int array variable, "a"
	int n = (sizeof(a) / sizeof(int));
	/* -------------------------------------------- END OF VARIABLE DECLARATIONS ---------------------------------------------- */

	__asm {
						mov ebx, 0				// move 0 into the EBX register (used to jump to index position inside int array "a")
						sub n, 1				// (n -= 1)
						mov i, 0				// (i = 0)
						mov j, 0				// (j = 0)
						mov ecx, n				// (ECX = n) (controls the number of loops)
		topouter:		mov eax, a[ebx]			// (EAX = a[EBX])	/**---------------------- TOP OF OUTER FOR LOOP ----------------------**/
						mov min, eax			// (min = a[EBX]) (used to store the current minimum value in the array "a")
						add ebx, 4              // (EBX += 4)
						mov edx, i				// (EDX = i)
						mov minPosition, edx	// (minPosition = i)
						mov j, edx				// (j = i)
						add j, 1				// (j += 1)
		topinner:		mov eax, j				// (EAX = j)	/**------------------------ TOP OF INNER FOR LOOP ------------------------**/
						mul four				// (j *= 4)
						mov ebx, eax			// (EBX = j * 4) (multiplying by 4 is to move ahead one index position in the int array "a")
						mov eax, a[ebx]			// (EAX = a[j])
						mov first, eax			// (first = a[j])
						mov eax, minPosition	// (EAX = minPosition)
						mul four				// (minPosition *= 4)
						mov ebx, eax			// (EBX = minPosition * 4) (multiplying by 4 is to move ahead one index position in the int array "a")
						mov eax, a[ebx]			// (EAX = a[minPosition])
						mov second, eax			// (second = a[minPosition])
						cmp first, eax			// compare "first" (a[j]) and "second" (a[minPosition])
						jl xiftrue				// if(a[j] < a[minPosition]) then jump to "xiftrue"
						mov eax, j				// (EAX = j)
						add j, 1				// (j += 1)
						cmp eax, n				// compare "j" (increments throughout program, always i + 1) to "n" (number of elements in "a" minus 1)
						jl topinner				// if(j < n) then jump to "topinner" (top of inside for loop)
						jmp xswap				// jump to "xswap" (to swap minimum value left in unsorted array to lowest unsorted index in "a")
		xiftrue:		mov eax, j				// [a[j] < a[minPosition]] (EAX = j)
						mul four				// (j *= 4)
						mov ebx, eax			// (EBX = j * 4) (multiplying by 4 is to move ahead one index position in the int array "a")
						mov eax, a[ebx]			// (EAX = a[j])
						mov min, eax			// (min = a[j])
						mov eax, j				// (EAX = j)
						mov minPosition, eax	// (minPosition = j)
						jmp topinner			// jump to "topinner" to finish checking the rest of the array
		xswap:			mov eax, i				// (EAX = i)
						mul four				// (i *= 4)
						mov ebx, eax			// (EBX = i * 4) (multiplying by 4 is to move ahead one index position in the int array "a")
						mov eax, a[ebx]			// (EAX = a[i])
						mov temp, eax			// (temp = a[i])
						mov eax, minPosition	// (EAX = minPosition)
						mul four				// (minPosition *= 4) 
						mov ebx, eax			// (EBX = minPosition * 4) (multiplying by 4 is to move ahead one index position in the int array "a")
						mov eax, a[ebx]			// (EAX = a[minPosition])
						mov tempTwo, eax		// (tempTwo = a[minPosition])
						mov eax, i				// (EAX = i)
						mul four				// (i *= 4)
						mov ebx, eax			// (EBX = i * 4)
						mov eax, tempTwo		// (EAX = a[minPosition])
						mov a[ebx], eax         // (a[i] = a[minPosition])
						mov eax, minPosition	// (EAX = minPosition)
						mul four				// (minPosition *= 4)
						mov ebx, eax			// (EBX = minPosition * 4) (multiplying by 4 is to move ahead one index position in the int array "a")
						mov eax, temp			// (EAX = a[i])
						mov a[ebx], eax			// (a[minPosition] = a[i])
						add i, 1				// (i += 1)
						mov edx, i				// (EDX = i)
						cmp n, edx				// compare "n" (number of elements in "a" minus 1) to "i" (increments throughout program)
						jg topouter				// if(n > i) then jump to "topouter" (top of outer for loop)
						jmp printingloop		// jump to "printingloop" (the loop used to print out every element of the int array "a")
		printingloop:	mov i, 0				// (i = 0)
						mov eax, n				// (EAX = n)
						cmp i, eax				// compare "i" (int counter variable) to "n" (number of elements in "a" minus 1)
						jl printarray			// if(i < n) then jump to "printarray" (print the int array "a")
						jmp doneprinting		// if(i >= n) then jump to "doneprinting" (exit the program)
		printarray:		mov eax, i				// (EAX = i)
						mul four				// (i *= 4)
						mov ebx, eax			// (EBX = i * 4) (multiplying by 4 is to move ahead one index position in the int array "a")
						mov eax, a[ebx]			// (EAX = a[i])
						mov current, eax		// (current = a[i])
						mov edx, current		// (EDX = a[i]) (EDX register is used for input and output)
	}

	printf("%d, ", current);					// print to the terminal the value inside the int variable "current"

	__asm {
						mov eax, i				// (EAX = i)
						cmp eax, n				// compare "i" (int counter variable) to "n" (number of elements in "a" minus 1)
						jl inci					// if(i < n) then jump to "inci" (used to increment "i" and jump back to top of printing loop)
						jmp doneprinting		// jump to "doneprinting" (exit the program)
		inci:			add i, 1				// (i += 1)
						jmp printarray			// jump back up to the top of "printarray" (the printing array code)
		doneprinting:	nop						// NO OPERATION (exit the program)
	}
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