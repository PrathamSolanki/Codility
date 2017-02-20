/*Write a function:

    int solution(int A[], int N);

that, given a non-empty zero-indexed array A of N integers, returns the minimal positive integer (greater than 0) that does not occur in A.

For example, given:
  A[0] = 1
  A[1] = 3
  A[2] = 6
  A[3] = 4
  A[4] = 1
  A[5] = 2

the function should return 5.

Assume that:

        N is an integer within the range [1..100,000];
        each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].

Complexity:

        expected worst-case time complexity is O(N);
        expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).

Elements of input arrays can be modified.*/

//========================Solution===========================================
#include <stdio.h>

int solution(int A[], int N);

void main(void)
{
	int N = 7;
    	int A[] = {-1, -6, 0, 3, -4, -5, -7};
	
	int MissingInteger = solution(A,N);
	printf("Missing Integer: %d\n", MissingInteger);
}

int solution(int A[], int N)
{
	/**************************************************
	 * 1. Sort A in ascending order.		  *
	 * 2. if (A[i+1] == A[i] || A[i+1] == A[i] + 1)   *
	 *	continue; 				  *
	 *    else 					  * 
	 *	check if A[i]+1 is negative because we    *  
         *	can return only values that are greater   *
         *	than 0 	and if A[i]+1 is not negative     *
	 *      or zero than return it.			  * 
	 *************************************************/

//-------------------------Sort A------------------------------------------
	int i, j, temp;

	for(i = 0; i < N; i++)
	{
		for(j = i + 1; j < N; j++)
		{
			if(A[i] > A[j])
			{
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}
//-------------------------------------------------------------------------

	if(N == 1 && A[0] == 1)
		return 2;

	else if (N == 1 && A[0] > 1)
		return 1;

	else if(A[0] > 0 && A[0] == 2)
		return 1;

	for(i = 0; i < N - 1; i++)
	{
		if (A[i+1] == A[i] || A[i+1] == A[i] + 1)
			continue;
		else
			if (A[i]+1 <= 0)
				continue;
			else
				return A[i] + 1;
	}
	return 1;
}
