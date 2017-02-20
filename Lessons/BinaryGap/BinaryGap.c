/*A binary gap within a positive integer N is any maximal sequence of consecutive zeros 
that is surrounded by ones at both ends in the binary representation of N.

For example, number 9 has binary representation 1001 and contains a binary gap of length 2.
The number 529 has binary representation 1000010001 and contains two binary gaps: 
one of length 4 and one of length 3. The number 20 has binary representation 10100 
and contains one binary gap of length 1. The number 15 has binary representation 1111 
and has no binary gaps.

Write a function:

    int solution(int N);

that, given a positive integer N, returns the length of its longest binary gap. 
The function should return 0 if N doesn't contain a binary gap.

For example, given N = 1041 the function should return 5, because 
N has binary representation 10000010001 and so its longest binary gap is of length 5.

Assume that:

        N is an integer within the range [1..2,147,483,647].

Complexity:

        expected worst-case time complexity is O(log(N));
        expected worst-case space complexity is O(1).
*/

#include <stdio.h>

int solution(int N);

void main(void)
{
	int N = 0;
	printf("Enter an integer: ");
	scanf("%d", &N);
	int BinaryGap = solution(N);
	printf("Binary Gap: %d\n", BinaryGap);
}

int solution(int N)
{
	int count = 0;
	int prev_count = 0;

	if (N <= 3)
	{
		return 0;
	}

	else
	{
		LOOP : 
		if(N%2 == 1 && N/2 != 0)
		{
			if(count >= prev_count)
			{
				prev_count = count;
			}
			count = 0;
			
			N = N/2;

			if (N%2 == 1)
			{
				goto LOOP;
			}
			
			while(N%2 != 1 && N/2 != 0)
			{
				count++;
				N = N/2;
			}
			goto LOOP;
		}

		else if(N%2 == 0 && N/2 != 0)
		{
			N = N/2;
			goto LOOP;
		}

		if (prev_count >= count)
		{
			return prev_count; 
		}

		else
		{
			return count;
		}
	}
}