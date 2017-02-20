/*A non-empty zero-indexed array A consisting of N integers is given.

A permutation is a sequence containing each element from 1 to N once, and only once.

For example, array A such that:
    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2

is a permutation, but array A such that:
    A[0] = 4
    A[1] = 1
    A[2] = 3

is not a permutation, because value 2 is missing.

The goal is to check whether array A is a permutation.

Write a function:

    int solution(int A[], int N);

that, given a zero-indexed array A, returns 1 if array A is a permutation and 0 if it is not.

For example, given array A such that:
    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2

the function should return 1.

Given array A such that:
    A[0] = 4
    A[1] = 1
    A[2] = 3

the function should return 0.

Assume that:

        N is an integer within the range [1..100,000];
        each element of array A is an integer within the range [1..1,000,000,000].

Complexity:

        expected worst-case time complexity is O(N);
        expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).

Elements of input arrays can be modified.*/

#include <stdio.h>
#include <string.h>

int solution(int A[], int N);

void main(void)
{
	int A[] = {4, 1, 3, 2};
	int N = 4;
	printf("Perm?: %d\n", solution(A,N));

	int B[] = {4, 1, 3};
	N = 3;
	printf("Perm?: %d\n", solution(B,N));
}

int solution(int A[], int N)
{
	int i;
	int smallest = A[0];
	int largest = 0;
	int sum = 0;
	int arraySum = 0;
	int requiredSum = 0;

	if(N == 1 && A[0] != 1)
		return 0;

	for(i = 0; i < N; i++)
	{
		if(A[i] < smallest)
			smallest = A[i];
		
		if(A[i] > largest)
			largest = A[i];

		arraySum += A[i];		
	}

	for(i = smallest; i <= largest; i++)
	{
		requiredSum += i; 
	}		
	
	_Bool count[largest+1];
	memset(count, 0, (largest+1)*sizeof(_Bool));

	for(i = 0; i < N; i++)
	{
		if(count[A[i]] == 1)
			continue;

		else
		{
			count[A[i]] = 1;
			sum += 1;
		}
	}

	if(arraySum == requiredSum && sum == largest)
		return 1;

	else 
		return 0;
}
