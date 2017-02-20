/*A zero-indexed array A consisting of N integers is given.
Rotation of the array means that each element is shifted right by one index,
and the last element of the array is also moved to the first place.

For example, the rotation of array A = [3, 8, 9, 7, 6] is [6, 3, 8, 9, 7].
The goal is to rotate array A K times; that is,
each element of A will be shifted to the right by K indexes.

Write a function:

    struct Results solution(int A[], int N, int K);

that, given a zero-indexed array A consisting of N integers and an integer K,
returns the array A rotated K times.

For example, given array A = [3, 8, 9, 7, 6] and K = 3,
the function should return [9, 7, 6, 3, 8].

Assume that:

        N and K are integers within the range [0..100];
        each element of array A is an integer within the range [−1,000..1,000].

In your solution, focus on correctness. 
The performance of your solution will not be the focus of the assessment.*/

#include <stdio.h>

int* solution(int A[], int N, int K);

void main(void)
{
	int N = 5;
	int K= 3;
	int i,j = 0;

	int A[] = {3, 8, 9, 7, 6};
	printf("Input Array:\n");
	for (i = 0; i < N; i++)
	{
		printf("%d\n", A[i]);
	}

	printf("Rotated Array:\n");
	int *result = solution(A, N, K);
	for (i = 0; i < N; i++)
	{
		printf("%d\n", result[i]);
	}
}

int* solution(int A[], int N, int K)
{

	#define MAX_SIZE 256
	static int* result;
	result = malloc(MAX_SIZE * sizeof(int));

	//static int result[N];
	int i, j;

	for (i = 0; i < K; i++)
	{
		int last = A[N-1];
		for (j = N-1; j > 0; j--)
		{
			A[j] = A[j-1];
		}
		A[0] = last;
	}

	for (i = 0; i < N; i++)
	{
		result[i] = A[i];
	}

	return result;
}

/* Rotation logic
	for (i = 0; i < K; i++)
	{
		int last = A[N-1];
		for (j = N-1; j > 0; j--)
		{
			A[j] = A[j-1];
		}
		A[0] = last;
	}
*/	