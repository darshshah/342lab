/* Group No-13
   Members:
	1) Anish Parikh (asp@andrew.cmu.edu)
	2) Darsh Shah (darshs@andrew.cmu.edu)
	3) Subramaniam Srisankaran (ssrisank@andrew.cmu.edu)
*/



#include <stdlib.h>
#include <stdio.h>

/**
 * Function: oddball
 * Description: Baseline implementation for finding the number that
 *   occurs only once in the array.
 * Arguments:
 *   arr - pointer to start of integer array
 *   len - number of elements in array
 * Return:
 *   The number that occurs only once
 */
#ifdef DEFAULT
int oddball(int *arr, int len) {
	int i, j;
	int foundInner;
	int result = 0;

	for (i = 0; i < len; i++) {
		foundInner = 0;
		for (j = 0; j < len; j++) {
			if (i == j) {
				continue;
			}
			if (arr[i] == arr[j]) {
				foundInner = 1;
			}
		}
		if (foundInner != 1) {
			result = arr[i];
		}
	}

	return result;
}
#endif

#ifdef OPTIMIZE1
/* We take the sum of all the elements in the array and then subtract
this sum from twice the sum of elements from 1 to n (n *(n+1)) to get the number
which occurs only once in the given array */ 
int oddball(int *arr, int len) 
{
	int i,sum=arr[0]+arr[1]; 
	int n=(len+1)/2; 
	for(i=2;i<len;i++)
	{
		sum+=arr[i];
	}
	return ((n*(n+1))-sum);
}
#endif

#ifdef OPTIMIZE2
/* The first optimization fails in the case where the value of sum exceeds the 
maximum range of an integer data type. To overcome this we have defined a second method 
where we use xoring to remove the numbers which occur in pairs and get the required number*/
int oddball(int *arr, int len) {
	int xor= arr[0] ^ arr[1],i;

	for(i=2;i<len;i++)
	{
		xor^=arr[i];
	}
	return xor;
}
#endif

/**
 * Function: randGenerator
 * Description: Generate a random array that is in compliance with
 *   lab specification
 * Arguments:
 *   arr - pointer to start of integer array
 *   len - number of elements in array
 * Return:
 *   Unused, but feel free to utilize it.
 */

int randGenerator(int *arr, int len) {
	int i, j, r, rcount;
	for (i = 0; i < len; i++) {
		do {
			rcount = 0;
			r = rand()%(len/2 + 1) + 1;
			for (j = 0; j < i && rcount < 2; j++) {
				if (arr[j] == r) {
					rcount++;
				}
			}
		} while(rcount >= 2);
		arr[i] = r;
		printf("%d ", r);
	}
	printf("\nDone generating\n");
	return 0;
}




