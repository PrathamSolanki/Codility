/*A non-empty zero-indexed array A consisting of N integers is given. 
Array A represents numbers on a tape.

Any integer P, such that 0 < P < N, 
splits this tape into two non-empty parts: A[0], A[1], ..., A[P − 1] 
and A[P], A[P + 1], ..., A[N − 1].

The difference between the two parts is the value of: 
|(A[0] + A[1] + ... + A[P − 1]) − (A[P] + A[P + 1] + ... + A[N − 1])|

In other words, it is the absolute difference between the sum of the first part 
and the sum of the second part.

For example, consider array A such that:
  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3

We can split this tape in four places:

        P = 1, difference = |3 − 10| = 7
        P = 2, difference = |4 − 9| = 5
        P = 3, difference = |6 − 7| = 1
        P = 4, difference = |10 − 3| = 7

Write a function:

    int solution(int A[], int N);

that, given a non-empty zero-indexed array A of N integers, 
returns the minimal difference that can be achieved.

For example, given:
  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3

the function should return 1, as explained above.

Assume that:

        N is an integer within the range [2..100,000];
        each element of array A is an integer within the range [−1,000..1,000].

Complexity:

        expected worst-case time complexity is O(N);
        expected worst-case space complexity is O(N), 
        beyond input storage (not counting the storage required for input arguments).

Elements of input arrays can be modified.*/


#include <stdio.h>
#include <math.h>

int solution(int A[], int N);

void main(void)
{
  int N = 5;
  int A[] = {3, 1, 2, 4, 3};

  int minimalDifference = solution(A, N);
  printf("Minimal Difference: %d\n", minimalDifference);
}

int solution(int A[], int N)
{
 int p, i;
 int leftSum = 0;
 int rightSum = 0;
 int difference[N-1];

 for(p = 1; p < N; p++)
 {
	leftSum = 0;
	rightSum = 0;
 
	for(i = 0; i < p; i++)
	{
		leftSum = leftSum + A[i];
	}

	for(i = p; i < N; i++)
	{
		rightSum = rightSum + A[i];
	}

	printf("leftSum: %d, rightSum: %d\n", leftSum, rightSum);

	//difference[p-1] = abs(leftSum - rightSum);
  
  int temp = leftSum - rightSum;

  if (temp < 0)
   {
     temp = temp*(-1);
   } 

 difference[p-1] = temp;

 } 

 int minimalDifference = difference[0];

 //printf("Differences\n");

 //printf("%d\n", difference[0]); 

 for(i = 1; i < N-1; i++)
 {
	//printf("%d\n", difference[i]);

	if(difference[i] < minimalDifference)
	{
		minimalDifference = difference[i];
	} 
 } 

 return minimalDifference;

}

